#include "pch.h"
#include "stockDisplay_Form.h"
using namespace System::Windows::Forms::DataVisualization::Charting;

namespace CppCLRWinFormsProject {
	System::Void stockDisplay_Form::loadStocks_Button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		
		if (loadData_OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK);
		//call the open file dialog, if the dialog loads a filepath successfully, the function 
		//loadData_OpenFileDialog_FileOk will be called
	}
	System::Void stockDisplay_Form::loadData_OpenFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		formLoader();
		//call formLoader function
		primaryFormControlsRelocation();
		//relocate controls for primary form
		for (int i = 1; i < loadData_OpenFileDialog->FileNames->Length; i++)
		{
			stockDisplay_Form^ secondaryForms = gcnew stockDisplay_Form();
			//create a new form
			secondaryForms->secondaryFormsInitialization(this->start_DateTimePicker->Value, this->end_DateTimePicker->Value,
				this->loadData_OpenFileDialog->FileNames[i]);
			//call secondaryFormsInitialization
			secondaryForms->formLoader();
			//call the formloader function
			secondaryForms->secondaryFormsControlsRelocation();
			//reorder its form controls
			secondaryForms->Show();
			//make form visible
		}
	}
	List<Candlestick^>^ stockDisplay_Form::goReadFile(String^ filePath) {
		List<Candlestick^>^ tempList = gcnew List<Candlestick^>(1024);
		//allocate space for a temporary list which will be returned
		String^ referenceString = "Date,Open,High,Low,Close,Adj Close,Volume";
		//this string is simply for the purpose of comparing the first line of the csv file so that it can
		//be verified to be in the right format
		StreamReader^ sr = gcnew StreamReader(filePath);
		//stream reader is a class that reads characters from a file
		String^ line = sr->ReadLine();
		//read the first line of the file		
		if (line == referenceString)
			//if statement checks that the first row is equal to the data sections of the stock data
		{
			line = sr->ReadLine();
			//because the column names have been checked, read the first line of actual data
			while (line != nullptr)
				//will loop over each line, if there is no more data, line will = null and break the loop
			{
				Candlestick^ cs = gcnew Candlestick(line);
				//call constructor of candlestick so that it will create a new candlestick based on the input data
				tempList->Add(cs);
				//add the new candlestick to the list
				line = sr->ReadLine();
				//go to the next line in the file
			}
		}
		else
		{
			Text = "Invalid File";
			//changes the text of the if the columns are not in the correct format 
		}
		sr->Close();
		//close file
		return tempList;
		//return the temporary list
	}
	System::Void stockDisplay_Form::goReadFile() {
		if (candlestick_List != nullptr)
			//test if candlesticks is instantiated
			candlestick_List->Clear();
		//if the list of candlesticks already has data, it needs to be cleared
		else
			//if candlesticks not instantiated
			candlestick_List = gcnew List<Candlestick^>(1024);
		//instantiate candlesticks
		candlestick_List = goReadFile(loadData_OpenFileDialog->FileName);
		//set candlesticks to the result of goReadFile which is defined above this function
	}
	System::Void stockDisplay_Form::formLoader() {
		goReadFile();
		//go read file in the openfile dialog
		candlesticksToSmartCandlesticks();
		//convert candlesticks to smart candlesticks
		filterCandlesticks();
		//filter candlesticks
		updateStock_Visuals();
		//update visuals
		Text = loadData_OpenFileDialog->FileName;
		//update text
	}
	List<Candlestick^>^ stockDisplay_Form::candlesticksToSmartCandlesticks(List<Candlestick^>^ csList) {
		List<Candlestick^>^ returnList = gcnew List<Candlestick^>(csList->Count);
		//allocate space for a returnList
		for each(Candlestick^ cs in csList)
		{
			SmartCandlestick^ smartCS = gcnew SmartCandlestick(cs);
			//call smartcandlestick constructor with candlestick as an arguement
			returnList->Add(smartCS);
			//add candlestick to returnList
		}
		return returnList;
		//return list
	}
	System::Void stockDisplay_Form::candlesticksToSmartCandlesticks() {
		if (candlestick_List == nullptr) return;
		//if candlestickList is null do nothing
		candlestick_List = candlesticksToSmartCandlesticks(candlestick_List);
		//convert candlesticklist to a smart candlestickList
	}
	List<Candlestick^>^ stockDisplay_Form::filterCandlesticks(List<Candlestick^>^ csList, DateTime start, DateTime end) {
		List<Candlestick^>^ tempList = gcnew List<Candlestick^>(csList->Count);
		//allocate space only for the potential max size of the candlestick list
		for (int i = 0; i < csList->Count; i++)
			//loop through all of the candlesticks
		{
			Candlestick^ cs = csList[i];
			//create a copy of the candlestick data row for row
			if (cs->date > end)
				//because yahoo data is sorted in ascending date order, just test for end date to break 
				break;
			//stop loop			
			if (start <= cs->date)
				//if the date of the current candlestick is too early, dont add
				tempList->Add(cs);
			//if date is past start date picker, add to the list
		}
		//convert the List to a BindingList
		return tempList;
		//return the BindingList
	}
	System::Void stockDisplay_Form::filterCandlesticks() {
		if (candlestick_List != nullptr)
			//test for the exception that candlestickList is nullptr
			boundCandlestick_List = gcnew BindingList<Candlestick^>(
				filterCandlesticks(candlestick_List, start_DateTimePicker->Value, end_DateTimePicker->Value));
		//set the boundCandlestick_List variable within stockDisplay_Form equal to the result of
		//filterCandlesticks(List<Candlestick^>^csList, DateTime start, DateTime end) which is defined above
	}
	System::Void stockDisplay_Form::updateStock_Visuals() {
		stock_Chart->DataSource = boundCandlestick_List;
		//set the stock_Chart data source to the bound candlesticks, 
		//however the chart recieves the data and does nothing with it until it is bound to the chart
		stock_Chart->DataBind();
		//bind the data to the chart so that it displays
		setTitles();
		//enable the titles
		normalizeStockChart();
		//normalize stock chart
		fillComboBox();
		//fill combobox
		updateAnnotations();
		//call updateannotations
	}
	System::Void stockDisplay_Form::setTitles() {
		if (stock_Chart->Series->Count > 0 && stock_Chart->Series[0]->Points->Count > 0)
			//tests to see if the series in the chart exists and if there are any points in the chart
			for each (Title ^ title in stock_Chart->Titles)
				//iterate through all the titles in the chart
				title->Visible = true;
		//set the visibility to true
		else
			for each (Title ^ title in stock_Chart->Titles)
				//iterate through all the titles in the chart
				title->Visible = false;
		//set the visibility to false
	}
	System::Void stockDisplay_Form::commonUpdateControls() {
		update_Button->Enabled = true;
		//enable update_Button
		update_Button->Visible = true;
		//show update_Button
		update_Button->Size = System::Drawing::Size(124, 20);
		//update button size change
		stock_Chart->Enabled = true;
		//enable stock_Chart
		stock_Chart->Visible = true;
		//make stock_Chart visible
		candlestickPattern_ComboBox->Visible = true;
		//show comboBox
		candlestickPattern_ComboBox->Enabled = true;
		//enable combobox
		resizeForm();
		//resize form size
	}
	System::Void stockDisplay_Form::primaryFormControlsRelocation() {
		commonUpdateControls();
		//call common controls update
		update_Button->Location = System::Drawing::Point(145, 530);
		//change the update_Button location
		loadStocks_Button->Location = System::Drawing::Point(12, 530);
		//change the loadStocks_Button location
		loadStocks_Button->Size = System::Drawing::Size(124, 20);
		//set loadstocks button to new size
		startDate_Label->Location = System::Drawing::Point(284, 533);
		//change the startDate_Label location 
		start_DateTimePicker->Location = System::Drawing::Point(354, 530);
		//change the start_DateTimePicker location
		endDate_Label->Location = System::Drawing::Point(564, 533);
		//change the endDate_Label location
		end_DateTimePicker->Location = System::Drawing::Point(634, 530);
		//change the end_DateTimePicker location
		candlestickPattern_ComboBox->Location = System::Drawing::Point(854, 530);
		//change combobox location
		//all of the change locations drag the controls down to the bottom
	}
	System::Void stockDisplay_Form::secondaryFormsControlsRelocation() {
		commonUpdateControls();
		//call common controls update
		loadStocks_Button->Enabled = false;
		//disable loadStock button
		loadStocks_Button->Visible = false;
		//hide loadStock button
		update_Button->Location = System::Drawing::Point(12, 530);
		//change update_Button location
		startDate_Label->Location = System::Drawing::Point(164, 533);
		//change the startDate_Label location
		start_DateTimePicker->Location = System::Drawing::Point(234, 530);
		//change the start_DateTimePicker location
		endDate_Label->Location = System::Drawing::Point(444, 533);
		//change the endDate_Label location
		end_DateTimePicker->Location = System::Drawing::Point(514, 530);
		//change the end_DateTimePicker location
		candlestickPattern_ComboBox->Location = System::Drawing::Point(734, 530);
		//change combobox location
		//all of the change locations drag the controls down to the bottom
	}
	System::Void stockDisplay_Form::resizeForm(int x, int y) {
		this->Width = x;
		//resize this form's width
		this->Height = y;
		//resize this form's height
	}
	System::Void stockDisplay_Form::resizeForm() {
		resizeForm(1116, 600);
		//call resizeForm to resize to the specified dimensions
	}
	System::Void stockDisplay_Form::update_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		filterCandlesticks();
		//filter candlesticks which will change data if the date time pickers are different 
		updateStock_Visuals();
		//call update stock chart data method		
	}
	System::Void stockDisplay_Form::normalizeStockChart() {
		if (boundCandlestick_List->Count <= 0)
			return;
		//if boundcandlestickList has no candlesticks, end function
		double min = boundCandlestick_List[0]->low;
		//variable of minimum for the chart area ohlc
		double max = boundCandlestick_List[0]->high;
		//variable of maximum for the chart area ohlc
		unsigned long long int minVol = boundCandlestick_List[0]->volume;
		//variable of minimum for the chart area volume
		unsigned long long int maxVol = boundCandlestick_List[0]->volume;
		//variable of maximum for the chart area volume
		for (int i = 1; i < boundCandlestick_List->Count; i++)
		//iterate through all candlesticks
		{
			if (min > boundCandlestick_List[i]->low)
			//if min is greater than the current candlestick low
				min = boundCandlestick_List[i]->low;
				//set min to current candlestick low
			if (max < boundCandlestick_List[i]->high)
			//if max is less than the current candlestick high
				max = boundCandlestick_List[i]->high;
				//set max to current candlestick high
			if (minVol > boundCandlestick_List[i]->volume)
			//if minVol is greater than the current candlestick volume
				minVol = boundCandlestick_List[i]->volume;
				//set minVol to current candlestick volume
			if (maxVol < boundCandlestick_List[i]->volume)
			//if maxVol is less than the current candlestick volume
				maxVol = boundCandlestick_List[i]->volume;
				//set maxVol to current candlestick high
		}
		//*
		Axis^ a = stock_Chart->ChartAreas[0]->AxisY;
		//set pointer a to the y axis of chart area ohlc
		a->Maximum = max + .02 * max;
		//normalize maximum
		a->Minimum = min - .02 * min;
		//normalize minimum
		a = stock_Chart->ChartAreas[1]->AxisY;
		//set pointer a to the y axis of chart area volume
		a->Maximum = maxVol + .02 * maxVol;
		//normalize maximum
		a->Minimum = minVol - .02 * minVol;
		//normalize minimum
		//*/
	}
	System::Void stockDisplay_Form::fillComboBox() {
		for each (Candlestick^ cs in boundCandlestick_List)
		{
			SmartCandlestick^ smartCS = dynamic_cast<SmartCandlestick^>(cs);
			//iterate through each candlestick until a smartcandlestick is found
			//dynamically cast Candlestick^ to a SmartCandlestick^ to have access to SmartCandlestick functions and members
			if (smartCS != nullptr)
			{
				for each (String^ key in smartCS->patterns->Keys)
				//iterate through all the patterns keys
					if(!candlestickPattern_ComboBox->Items->Contains(key))
						candlestickPattern_ComboBox->Items->Add(key);
						//add keys to comboboxif they are not already there
				break;
				//end the loop
			}
		}
	}
	System::Void stockDisplay_Form::updateAnnotations() {
		if (stock_Chart->Annotations->Count > 0) stock_Chart->Annotations->Clear();
		//if stock chart has any annotations, clear them
		if (annotationList == nullptr) annotationList = gcnew List<ArrowAnnotation^>();
		//if annotationList not initialized, intialize
		else annotationList->Clear();
		//otherwise clear annotations
		if (dataPointList == nullptr) dataPointList = gcnew List<DataPoint^>();
		//if dataPointList not initialized, intialize
		else dataPointList->Clear();
		//otherwise clear data points
		if (candlestickPattern_ComboBox->SelectedItem == nullptr) return;
		//execute nothing if combobox has nothing selected
		String^ key = dynamic_cast<String^>(candlestickPattern_ComboBox->SelectedItem);
		//cast the selected item to string
		double annotationSize = 3.157894;
		//default size for annotation
		if (stock_Chart->Series[0]->Points->Count >= 19)
			annotationSize = 3 * (stock_Chart->ChartAreas[0]->AxisX->Maximum - stock_Chart->ChartAreas[0]->AxisX->Minimum)
			/ stock_Chart->Series[0]->Points->Count;;
			//dynamic size of annotation column width of each datapoint
		if (annotationSize < 1) annotationSize = 1;
		//minimum size if annotation size is too small
		for (int i = 0; i < boundCandlestick_List->Count; i++)  {
			SmartCandlestick^ smartCS = dynamic_cast<SmartCandlestick^>(boundCandlestick_List[i]);
			//dynamically cast Candlestick^ to a SmartCandlestick^ to have access to SmartCandlestick functions and members
			if (smartCS == nullptr) continue;
			//go to next iteration if smartCS did not convert properly
			bool value;
			if (smartCS->patterns->TryGetValue(key, value)) 
			//test if the key exists in the patterns of candlestick
			{
				if (value == true)
				//if the key gives a value of true
				{
					ArrowAnnotation^ arrow = gcnew ArrowAnnotation();
					//declare arrow annotation
					DataPoint^ point = stock_Chart->Series[0]->Points[i];
					//set datapoint to the same point as the one on the chart
					//see https://learn.microsoft.com/en-us/dotnet/api/system.windows.forms.datavisualization.charting.datapoint?view=netframework-4.8.1
					// for more information
					dataPointList->Add(point);
					//add the point to the point list
					arrow->AxisX = stock_Chart->ChartAreas[0]->AxisX;
					//set arrow x-axis
					arrow->AxisY = stock_Chart->ChartAreas[0]->AxisY;
					//set arrow y-axis
					arrow->ArrowStyle = ArrowStyle::Simple;
					//set arrow style
					arrow->Height = annotationSize;
					//set arrow height
					arrow->Width = annotationSize;
					//set arrow width
					arrow->ArrowSize = 1.5 * annotationSize;
					arrow->SetAnchor(point);
					//anchor the arrow to the point
					stock_Chart->Annotations->Add(arrow);
					//add arrow to the chart
				}
			}
		}
	}
	System::Void stockDisplay_Form::secondaryFormsInitialization(DateTime start, DateTime end, String^ file) {
		this->start_DateTimePicker->Value = start;
		//set new form start date time picker to the same as this form's start date time picker
		this->end_DateTimePicker->Value = end;
		//set new form end date time picker to the same as this form's end date time picker
		this->loadData_OpenFileDialog->FileName = file;
		//set secondary form's openfile dialog name to the corresponding filename
	}
}