#pragma once
#include "SmartCandlestick.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for stockDisplay_Form
	/// </summary>
	public ref class stockDisplay_Form : public System::Windows::Forms::Form
	{
	public:
		stockDisplay_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~stockDisplay_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	//my variables
	protected: List<Candlestick^>^ candlestick_List;
	private: BindingList<Candlestick^>^ boundCandlestick_List;
	private: List<System::Windows::Forms::DataVisualization::Charting::ArrowAnnotation^>^ annotationList;
	private: List<System::Windows::Forms::DataVisualization::Charting::DataPoint^>^ dataPointList;
	//
	//visual element variables
	private: System::Windows::Forms::Label^ startDate_Label;
	private: System::Windows::Forms::Label^ endDate_Label;
	protected: System::Windows::Forms::DateTimePicker^ start_DateTimePicker;
	protected: System::Windows::Forms::DateTimePicker^ end_DateTimePicker;
	private: System::Windows::Forms::Button^ loadStocks_Button;
	private: System::Windows::Forms::Button^ update_Button;
	protected: System::Windows::Forms::OpenFileDialog^ loadData_OpenFileDialog;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ stock_Chart;
	private: System::Windows::Forms::ComboBox^ candlestickPattern_ComboBox;
	//
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			this->startDate_Label = (gcnew System::Windows::Forms::Label());
			this->endDate_Label = (gcnew System::Windows::Forms::Label());
			this->start_DateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->end_DateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->loadStocks_Button = (gcnew System::Windows::Forms::Button());
			this->stock_Chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->update_Button = (gcnew System::Windows::Forms::Button());
			this->loadData_OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->candlestickPattern_ComboBox = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stock_Chart))->BeginInit();
			this->SuspendLayout();
			// 
			// startDate_Label
			// 
			this->startDate_Label->AutoSize = true;
			this->startDate_Label->Location = System::Drawing::Point(184, 12);
			this->startDate_Label->Name = L"startDate_Label";
			this->startDate_Label->Size = System::Drawing::Size(69, 16);
			this->startDate_Label->TabIndex = 0;
			this->startDate_Label->Text = L"Start Date:";
			// 
			// endDate_Label
			// 
			this->endDate_Label->AutoSize = true;
			this->endDate_Label->Location = System::Drawing::Point(535, 12);
			this->endDate_Label->Name = L"endDate_Label";
			this->endDate_Label->Size = System::Drawing::Size(66, 16);
			this->endDate_Label->TabIndex = 1;
			this->endDate_Label->Text = L"End Date:";
			// 
			// start_DateTimePicker
			// 
			this->start_DateTimePicker->Location = System::Drawing::Point(273, 9);
			this->start_DateTimePicker->Name = L"start_DateTimePicker";
			this->start_DateTimePicker->Size = System::Drawing::Size(243, 22);
			this->start_DateTimePicker->TabIndex = 2;
			this->start_DateTimePicker->Value = System::DateTime(2022, 1, 1, 0, 0, 0, 0);
			// 
			// end_DateTimePicker
			// 
			this->end_DateTimePicker->Location = System::Drawing::Point(618, 7);
			this->end_DateTimePicker->Name = L"end_DateTimePicker";
			this->end_DateTimePicker->Size = System::Drawing::Size(243, 22);
			this->end_DateTimePicker->TabIndex = 3;
			this->end_DateTimePicker->Value = System::DateTime(2024, 2, 20, 13, 9, 50, 0);
			// 
			// loadStocks_Button
			// 
			this->loadStocks_Button->Location = System::Drawing::Point(12, 8);
			this->loadStocks_Button->Name = L"loadStocks_Button";
			this->loadStocks_Button->Size = System::Drawing::Size(166, 24);
			this->loadStocks_Button->TabIndex = 4;
			this->loadStocks_Button->Text = L"Load Stocks";
			this->loadStocks_Button->UseVisualStyleBackColor = true;
			this->loadStocks_Button->Click += gcnew System::EventHandler(this, &stockDisplay_Form::loadStocks_Button_Click);
			// 
			// stock_Chart
			// 
			chartArea1->AlignWithChartArea = L"ChartArea_Volume";
			chartArea1->Name = L"ChartArea_OHLC";
			chartArea2->Name = L"ChartArea_Volume";
			this->stock_Chart->ChartAreas->Add(chartArea1);
			this->stock_Chart->ChartAreas->Add(chartArea2);
			this->stock_Chart->Enabled = false;
			this->stock_Chart->Location = System::Drawing::Point(12, 12);
			this->stock_Chart->Name = L"stock_Chart";
			series1->ChartArea = L"ChartArea_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=0\\, 192\\, 0";
			series1->IsXValueIndexed = true;
			series1->Name = L"Series_OHLC";
			series1->XValueMember = L"date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValueMembers = L"high, low, open, close";
			series1->YValuesPerPoint = 4;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->ChartArea = L"ChartArea_Volume";
			series2->IsXValueIndexed = true;
			series2->Name = L"Series_Volume";
			series2->XValueMember = L"date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series2->YValueMembers = L"volume";
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			this->stock_Chart->Series->Add(series1);
			this->stock_Chart->Series->Add(series2);
			this->stock_Chart->Size = System::Drawing::Size(1443, 623);
			this->stock_Chart->TabIndex = 5;
			title1->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title1->DockedToChartArea = L"ChartArea_OHLC";
			title1->IsDockedInsideChartArea = false;
			title1->Name = L"title_OHLC";
			title1->Text = L"Open, High, Low, Close";
			title1->Visible = false;
			title2->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title2->DockedToChartArea = L"ChartArea_Volume";
			title2->IsDockedInsideChartArea = false;
			title2->Name = L"Title_Volume";
			title2->Text = L"Volume";
			title2->Visible = false;
			this->stock_Chart->Titles->Add(title1);
			this->stock_Chart->Titles->Add(title2);
			this->stock_Chart->Visible = false;
			// 
			// update_Button
			// 
			this->update_Button->Enabled = false;
			this->update_Button->Location = System::Drawing::Point(12, 8);
			this->update_Button->Name = L"update_Button";
			this->update_Button->Size = System::Drawing::Size(166, 24);
			this->update_Button->TabIndex = 6;
			this->update_Button->Text = L"Update";
			this->update_Button->UseVisualStyleBackColor = true;
			this->update_Button->Visible = false;
			this->update_Button->Click += gcnew System::EventHandler(this, &stockDisplay_Form::update_Button_Click);
			// 
			// loadData_OpenFileDialog
			// 
			this->loadData_OpenFileDialog->Filter = L"Monthly|*-Month.csv|Weekly|*-Week.csv|Daily|*Day.csv|All Files|*.*";
			this->loadData_OpenFileDialog->InitialDirectory = L"C:\\Users\\Cunde\\Desktop\\CIS 4930\\CIS 4930 C++ All Projects\\Stock Data";
			this->loadData_OpenFileDialog->Multiselect = true;
			this->loadData_OpenFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &stockDisplay_Form::loadData_OpenFileDialog_FileOk);
			// 
			// candlestickPattern_ComboBox
			// 
			this->candlestickPattern_ComboBox->Enabled = false;
			this->candlestickPattern_ComboBox->FormattingEnabled = true;
			this->candlestickPattern_ComboBox->Location = System::Drawing::Point(1000, 0);
			this->candlestickPattern_ComboBox->Name = L"candlestickPattern_ComboBox";
			this->candlestickPattern_ComboBox->Size = System::Drawing::Size(155, 24);
			this->candlestickPattern_ComboBox->TabIndex = 7;
			this->candlestickPattern_ComboBox->Visible = false;
			// 
			// stockDisplay_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 42);
			this->Controls->Add(this->candlestickPattern_ComboBox);
			this->Controls->Add(this->end_DateTimePicker);
			this->Controls->Add(this->start_DateTimePicker);
			this->Controls->Add(this->endDate_Label);
			this->Controls->Add(this->startDate_Label);
			this->Controls->Add(this->loadStocks_Button);
			this->Controls->Add(this->stock_Chart);
			this->Controls->Add(this->update_Button);
			this->Name = L"stockDisplay_Form";
			this->Text = L"Stock Selector";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stock_Chart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion






	protected: System::Void loadStocks_Button_Click(System::Object^ sender, System::EventArgs^ e);
			/// <summary>
			/// When the loadstocks_button is clicked, the system will show an open file dialog for a user to select one
			/// or more files.
			/// </summary>
	protected: virtual System::Void loadData_OpenFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
			/// <summary>
			/// If the files seleted are readable by the open file dialog, the selected file(s) will be read and will open 
			/// new windows for each selected files
			/// </summary>
	
	protected: List<Candlestick^>^ goReadFile(String^ filePath);
			/// <summary>
			/// Given a file path, this function will select the file, test if the headers of the csv file is valid.
			/// If it is valid, all the rows will be processed and have a candlestick produced for each, all the candlesticks
			/// will be added to a list.
			/// </summary>
			/// <param name="filePath">This arguement will be the string used to locate the file.</param>
			/// <returns>A list of Candlesticks representing the data in the csv file.</returns>
	protected: System::Void goReadFile();
		    /// <summary>
		    /// This function calls the goReadFile function above passing in as arguements the filename saved by the 
		    /// openFileDialog.
		    /// </summary> 
	protected: System::Void formLoader();
		   /// <summary>
		   /// When formLoader is called, it will read the file from the loadStockData_OpenFileDialog and will convert its candlesticks to
		   /// SmartCandlesticks, filter them, update its title and the stock chart
		   /// </summary>
	protected: virtual List<Candlestick^>^ candlesticksToSmartCandlesticks(List<Candlestick^>^);
		   /// <summary>
		   /// When candlesticksToSmartCandlesticks, it will take a candlestick list and convert its Candlesticks to SmartCandlesticks
		   /// and then return a list of SmartCandlesticks as a list of Candlesticks
		   /// </summary>
	protected: System::Void candlesticksToSmartCandlesticks();
		   /// <summary>
		   /// Calls the candlesticksToSmartCandlesticks funciton above and sets the candlestick list to the result of the function
		   /// </summary>	
	protected: List<Candlestick^>^ filterCandlesticks(List<Candlestick^>^ csList, DateTime start, DateTime end);
		   /// <summary>
		   /// This function will filter through a List of candlesticks and return a BindingList of candlesticks
		   /// between the start and end date.
		   /// </summary>
		   /// <param name="csList">List of candlesticks which will be filtered through.</param>
		   /// <param name="start">DateTime which represents the first date that will be counted as valid
		   /// and added to the return BindingList.</param>
		   /// <param name="end">DateTime which represents the last date that will be counted as valid
		   /// and added to the return BindingList.</param>
		   /// <returns>Returns a BindingList of candlesticks which are filtered by date.</returns>
	protected: System::Void filterCandlesticks();
		   /// <summary>
		   /// Since the function filterCandlesticks(List<Candlestick^> csList) is defined within the same namespace of the it simply uses the
		   /// variable candlestick_List which is already availible.
		   /// </summary>
	protected: System::Void updateStock_Visuals();
		   /// <summary>
		   /// When this function is called, it simply sets the stockDataGridView data source to boundCandlesticks. Also it sets the stock_Chart
		   /// data source to the binding list and binds the data to the chart.
		   /// </summary>
	protected: System::Void setTitles();
		   /// <summary>
		   /// When the setTitles function is called, it will loop through all the titles in the chart and display them. Also referenced chatGPT and microsoft C# 
		   /// Chart Library learn:: https://learn.microsoft.com/en-us/dotnet/api/system.windows.forms.datavisualization.charting.chart?view=netframework-4.8.1
		   /// </summary>
	protected: System::Void commonUpdateControls();
		   /// <summary>
	       /// When commonControlsUpdate is called, form controls will be resized and ordered for both primary and secondary forms
		   /// </summary>
	protected: System::Void primaryFormControlsRelocation();
		   /// <summary>
		   /// When primaryFormsControlsRelocation is called, commonControlsUpdate will be called and additional changes will be done that 
		   /// are specific to the primary form
		   /// </summary>
	protected: System::Void secondaryFormsControlsRelocation();
		   /// <summary>
	       /// When primaryFormsControlsRelocation is called, commonControlsUpdate will be called and additional changes will be done that 
	       /// are specific to the primary form
	       /// </summary>

	protected: System::Void resizeForm(int, int);
		   /// <summary>
		   /// When resizeForm is called, the form size will be changed to accomadate the chart to the specified dimensions from
		   /// the integer inputs.
		   /// </summary>
	protected: System::Void resizeForm();
		   /// <summary>
		   /// Calls the version of resize form above with fixed sizes.
		   /// </summary>
	protected: System::Void update_Button_Click(System::Object^ sender, System::EventArgs^ e);
		   /// <summary>
		   /// When the update button is clicked, it will filter the candlesticks according to the most recent update
		   /// to the dateTimePickers and then display the data in the dataGridView
		   /// </summary>
	protected: System::Void normalizeStockChart();
		   /// <summary>
		   /// When the normalizeStockChart function is called, the stockChart will have a defined max, minimum according
		   /// to a percentage of the highest and lowest data points in the candlesticks. In addition, the 
		   /// </summary>
	protected: System::Void fillComboBox();
		   /// <summary>
		   /// When the fillComboBox function is called, the combo box will be filled with the most common patterns
		   /// recognized by the SmartCandlestick
		   /// </summary>
	protected: System::Void updateAnnotations();
		   /// <summary>
		   /// When the setAnnotations function is called, the boundcandlestickList will be iterated over, so that each 
		   /// candlestick that has a true value for the selected pattern in the combobox will be annotated with an arrow
		   /// </summary>
	protected: System::Void secondaryFormsInitialization(DateTime, DateTime, String^);
		   /// <summary>
		   /// When the secondaryFormsInitialization function is called, it will set the same properties of the parent form for the date time pickers
		   /// </summary>
}; 
}
