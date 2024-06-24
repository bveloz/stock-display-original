#include "pch.h"
#include "stockPicker_Form.h"
using namespace System::Windows::Forms::DataVisualization::Charting;

namespace CppCLRWinFormsProject {
	System::Void stockPicker_Form::loadStock_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (loadData_OpenFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK);
		//call the open file dialog, if the dialog loads a filepath successfully, the function 
		//loadData_OpenFileDialog_FileOk will be called
		
	}
	System::Void stockPicker_Form::loadData_OpenFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		goReadFile();
		//calls the go read file method
		filterCandlesticks();
		//calls the filter candlesticks method
		updateStock_Visuals();
		//call update stock Data Grid View method

	}
	List<Candlestick^>^ stockPicker_Form::goReadFile(String^ filePath) {
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
	System::Void stockPicker_Form::goReadFile() {
		if (candlestick_List == nullptr)
			//tests if candlesticklist is instantiated
			candlestick_List = gcnew List<Candlestick^>(1024);
		//allocates space for list
		candlestick_List->Clear();
		//clear all of the candlesticks in case there is previous data which is now irellevent
		candlestick_List = goReadFile(loadData_OpenFileDialog->FileName);
		//calls the goReadFile function which is defined above and set candlestick_List to the result
	}
	List<Candlestick^>^ stockPicker_Form::filterCandlesticks(List<Candlestick^>^ csList, DateTime start, DateTime end) {
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
	System::Void stockPicker_Form::filterCandlesticks() {
		if(candlestick_List != nullptr)
			//test for the exception that candlestickList is nullptr
			boundCandlestick_List = gcnew BindingList<Candlestick^>(
				filterCandlesticks(candlestick_List, start_DateTimePicker->Value, end_DateTimePicker->Value));
			//set the boundCandlestick_List variable within stockPicker_Form equal to the result of
			//filterCandlesticks(List<Candlestick^>^csList, DateTime start, DateTime end) which is defined above
	}
	System::Void stockPicker_Form::updateStock_Visuals() {
		stock_DataGridView->DataSource = boundCandlestick_List;
		//set the stockDataGridview data source to the bound candlesticks
		stock_Chart->DataSource = boundCandlestick_List;
		//set the stock_Chart data source to the bound candlesticks, 
		//however the chart recieves the data and does nothing with it until it is bound to the chart
		stock_Chart->DataBind();
		//bind the data to the chart so that it displays
		setTitles();
		//enable the titles
	}
	System::Void stockPicker_Form::update_Button_Click(System::Object^ sender, System::EventArgs^ e) {
		filterCandlesticks();
		//filter candlesticks which will change data if the date time pickers are different 
		updateStock_Visuals();
		//call update stock Data Grid View method		
	}
	System::Void stockPicker_Form::setTitles() {
		if(stock_Chart->Series->Count > 0 && stock_Chart->Series[0]->Points->Count > 0)
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

}