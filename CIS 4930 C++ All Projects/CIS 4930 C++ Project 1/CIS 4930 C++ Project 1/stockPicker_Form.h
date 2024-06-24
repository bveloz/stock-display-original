#pragma once
#include "Candlestick.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for stockPicker_Form
	/// </summary>
	public ref class stockPicker_Form : public System::Windows::Forms::Form
	{
	private: List<Candlestick^>^ candlestick_List;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ stock_Chart;
	private: System::Windows::Forms::DataGridView^ stock_DataGridView;

	private: BindingList<Candlestick^>^ boundCandlestick_List;
	public:
		stockPicker_Form(void)
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
		~stockPicker_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	
	protected:

	private: System::Windows::Forms::Button^ update_Button;
	private: System::Windows::Forms::Button^ loadStock_Button;
	private: System::Windows::Forms::DateTimePicker^ start_DateTimePicker;
	private: System::Windows::Forms::DateTimePicker^ end_DateTimePicker;
	private: System::Windows::Forms::Label^ startDate_Label;
	private: System::Windows::Forms::Label^ endDate_Label;
	private: System::Windows::Forms::OpenFileDialog^ loadData_OpenFileDialog;


	protected:

	protected:

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
			this->update_Button = (gcnew System::Windows::Forms::Button());
			this->loadStock_Button = (gcnew System::Windows::Forms::Button());
			this->start_DateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->end_DateTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->startDate_Label = (gcnew System::Windows::Forms::Label());
			this->endDate_Label = (gcnew System::Windows::Forms::Label());
			this->loadData_OpenFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->stock_Chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->stock_DataGridView = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stock_Chart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stock_DataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// update_Button
			// 
			this->update_Button->Location = System::Drawing::Point(138, 560);
			this->update_Button->Name = L"update_Button";
			this->update_Button->Size = System::Drawing::Size(122, 35);
			this->update_Button->TabIndex = 0;
			this->update_Button->Text = L"Update";
			this->update_Button->UseVisualStyleBackColor = true;
			this->update_Button->Click += gcnew System::EventHandler(this, &stockPicker_Form::update_Button_Click);
			// 
			// loadStock_Button
			// 
			this->loadStock_Button->Location = System::Drawing::Point(10, 560);
			this->loadStock_Button->Name = L"loadStock_Button";
			this->loadStock_Button->Size = System::Drawing::Size(122, 35);
			this->loadStock_Button->TabIndex = 1;
			this->loadStock_Button->Text = L"Load Stock";
			this->loadStock_Button->UseVisualStyleBackColor = true;
			this->loadStock_Button->Click += gcnew System::EventHandler(this, &stockPicker_Form::loadStock_Button_Click);
			// 
			// start_DateTimePicker
			// 
			this->start_DateTimePicker->Location = System::Drawing::Point(414, 564);
			this->start_DateTimePicker->Name = L"start_DateTimePicker";
			this->start_DateTimePicker->Size = System::Drawing::Size(246, 22);
			this->start_DateTimePicker->TabIndex = 2;
			this->start_DateTimePicker->Value = System::DateTime(2022, 7, 1, 0, 0, 0, 0);
			// 
			// end_DateTimePicker
			// 
			this->end_DateTimePicker->Location = System::Drawing::Point(783, 564);
			this->end_DateTimePicker->Name = L"end_DateTimePicker";
			this->end_DateTimePicker->Size = System::Drawing::Size(243, 22);
			this->end_DateTimePicker->TabIndex = 3;
			this->end_DateTimePicker->Value = System::DateTime(2024, 2, 16, 0, 0, 0, 0);
			// 
			// startDate_Label
			// 
			this->startDate_Label->AutoSize = true;
			this->startDate_Label->Location = System::Drawing::Point(327, 569);
			this->startDate_Label->Name = L"startDate_Label";
			this->startDate_Label->Size = System::Drawing::Size(69, 16);
			this->startDate_Label->TabIndex = 4;
			this->startDate_Label->Text = L"Start Date:";
			// 
			// endDate_Label
			// 
			this->endDate_Label->AutoSize = true;
			this->endDate_Label->Location = System::Drawing::Point(698, 569);
			this->endDate_Label->Name = L"endDate_Label";
			this->endDate_Label->Size = System::Drawing::Size(66, 16);
			this->endDate_Label->TabIndex = 5;
			this->endDate_Label->Text = L"End Date:";
			// 
			// loadData_OpenFileDialog
			// 
			this->loadData_OpenFileDialog->FileName = L"Stock-Time.csv";
			this->loadData_OpenFileDialog->Filter = L"Monthly|*-Month.csv|Weekly|*-Week.csv|Daily|*Day.csv|All Files|*.*";
			this->loadData_OpenFileDialog->InitialDirectory = L"C:\\Users\\Cunde\\Desktop\\CIS 4930\\CIS 4930 C++ Project 1\\Stock Data";
			this->loadData_OpenFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &stockPicker_Form::loadData_OpenFileDialog_FileOk);
			// 
			// stock_Chart
			// 
			chartArea1->AlignWithChartArea = L"ChartArea_Volume";
			chartArea1->Name = L"ChartArea_OHLC";
			chartArea2->Name = L"ChartArea_Volume";
			this->stock_Chart->ChartAreas->Add(chartArea1);
			this->stock_Chart->ChartAreas->Add(chartArea2);
			this->stock_Chart->Location = System::Drawing::Point(12, 149);
			this->stock_Chart->Name = L"stock_Chart";
			series1->ChartArea = L"ChartArea_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=0\\, 192\\, 0";
			series1->Legend = L"Legend1";
			series1->LegendText = L" ";
			series1->Name = L"Series_OHLC";
			series1->XValueMember = L"date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValueMembers = L"high, low, open, close";
			series1->YValuesPerPoint = 4;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->ChartArea = L"ChartArea_Volume";
			series2->Legend = L"Legend1";
			series2->Name = L"Series_Volume";
			series2->XValueMember = L"date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series2->YValueMembers = L"volume";
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			this->stock_Chart->Series->Add(series1);
			this->stock_Chart->Series->Add(series2);
			this->stock_Chart->Size = System::Drawing::Size(1262, 385);
			this->stock_Chart->TabIndex = 7;
			title1->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title1->DockedToChartArea = L"ChartArea_OHLC";
			title1->IsDockedInsideChartArea = false;
			title1->Name = L"title_OHLC";
			title1->Text = L"Open, High, Low, Close";
			title1->Visible = false;
			title2->Alignment = System::Drawing::ContentAlignment::TopCenter;
			title2->DockedToChartArea = L"ChartArea_Volume";
			title2->IsDockedInsideChartArea = false;
			title2->Name = L"title_Volume";
			title2->Text = L"Volume";
			title2->Visible = false;
			this->stock_Chart->Titles->Add(title1);
			this->stock_Chart->Titles->Add(title2);
			// 
			// stock_DataGridView
			// 
			this->stock_DataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->stock_DataGridView->Location = System::Drawing::Point(12, 12);
			this->stock_DataGridView->Name = L"stock_DataGridView";
			this->stock_DataGridView->RowHeadersWidth = 51;
			this->stock_DataGridView->RowTemplate->Height = 24;
			this->stock_DataGridView->Size = System::Drawing::Size(1262, 131);
			this->stock_DataGridView->TabIndex = 8;
			// 
			// stockPicker_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1286, 612);
			this->Controls->Add(this->stock_DataGridView);
			this->Controls->Add(this->stock_Chart);
			this->Controls->Add(this->endDate_Label);
			this->Controls->Add(this->startDate_Label);
			this->Controls->Add(this->end_DateTimePicker);
			this->Controls->Add(this->start_DateTimePicker);
			this->Controls->Add(this->loadStock_Button);
			this->Controls->Add(this->update_Button);
			this->Name = L"stockPicker_Form";
			this->Text = L"Stock Picker";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stock_Chart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->stock_DataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void loadStock_Button_Click(System::Object^ sender, System::EventArgs^ e);
		/// <summary>
		/// When the button that says "Load Stock" is clicked", several functions will be called which
		/// will aid in loading in a file from the computer which contains stock data in a specified format.
		/// Format: Date, Open, High, Low, Close, Adj Close, Volume.
		/// </summary>

	private: System::Void loadData_OpenFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
		/// <summary>
		/// When the open file dialog returns a filename from a file path, it will be call the goReadFile, filterCandlesticks
		/// and the updateStock_Visuals function.
		/// </summary>
	private: List<Candlestick^>^ goReadFile(String^ filePath);
		/// <summary>
		/// Given a file path, this function will select the file, test if the headers of the csv file is valid.
		/// If it is valid, all the rows will be processed and have a candlestick produced for each, all the candlesticks
		/// will be added to a list.
		/// </summary>
		/// <param name="filePath">This arguement will be the string used to locate the file.</param>
		/// <returns>A list of Candlesticks representing the data in the csv file.</returns>
	private: System::Void goReadFile();
		/// <summary>
		/// Since the function goReadFile(String^ filePath) is defined within the same namespace as the
		/// variable candlestick_List it simply sets that variable to the result of the goReadFile(String^ filePath).
		/// </summary>
	private: System::Void filterCandlesticks();
		/// <summary>
		/// Since the function filterCandlesticks(List<Candlestick^> csList) is defined within the same namespace of the it simply uses the
		/// variable candlestick_List which is already availible.
		/// </summary>
	private: List<Candlestick^>^ filterCandlesticks(List<Candlestick^>^ csList, DateTime start, DateTime end);
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
	private: System::Void updateStock_Visuals();
		/// <summary>
		/// When this function is called, it simply sets the stockDataGridView data source to boundCandlesticks. Also it sets the stock_Chart
		/// data source to the binding list and binds the data to the chart.
		/// </summary>
	private: System::Void update_Button_Click(System::Object^ sender, System::EventArgs^ e);
		/// <summary>
		/// When the update button is clicked, it will filter the candlesticks according to the most recent update
		/// to the dateTimePickers and then display the data in the dataGridView
		/// </summary>
	private: System::Void setTitles();
		/// <summary>
		/// When the setTitles function is called, it will loop through all the titles in the chart and display them. Also referenced chatGPT and microsoft C# 
		/// Chart Library learn:: https://learn.microsoft.com/en-us/dotnet/api/system.windows.forms.datavisualization.charting.chart?view=netframework-4.8.1
		/// </summary>
};
}
