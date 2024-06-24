#pragma once
#include "stockDisplay_Form.h"
#include "Recognizer.h"
#include "Recognizer_Peak.h"
#include "Recognizer_Bearish.h"
#include "Recognizer_BearishEngulfing.h"
#include "Recognizer_Bullish.h"
#include "Recognizer_BullishEngulfing.h"
#include "Recognizer_BullishHarami.h"
#include "Recognizer_BearishHarami.h"
#include "Recognizer_Doji.h"
#include "Recognizer_DragonflyDoji.h"
#include "Recognizer_GravestoneDoji.h"
#include "Recognizer_Hammer.h"
#include "Recognizer_InvertedHammer.h"
#include "Recognizer_Marubozu.h"
#include "Recognizer_Neutral.h"
#include "Recognizer_Valley.h"
namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for stockRecognizer_Form
	/// </summary>
	public ref class stockRecognizer_Form : stockDisplay_Form
	{
	public:
		stockRecognizer_Form(void)
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
		~stockRecognizer_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	//my variables
	private: List<Recognizer^>^ recognizerList; 
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
			this->SuspendLayout();
			// 
			// stockRecognizer_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(873, 42);
			this->Name = L"stockRecognizer_Form";
			this->Text = L"stockRecognizer_Form";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: List<Recognizer^>^ instantiateRecognizers(List<Recognizer^>^);
		   /// <summary>
		   /// When instantiateRecognizer is called, the RecognizerList will be instantiated and filled with all of the Recognizers
		   /// </summary>
	private: System::Void instantiateRecognizers();
		   /// <summary>
		   /// When instantiateRecognizer is called, the version above will be called and will fill this forms recognizers
		   /// </summary>
	private: List<SmartCandlestick^>^ callAllRecognizers(List<SmartCandlestick^>^);
		   /// <summary>
		   /// When callAllRecognizers is called, the recognizerlist will be initialized, filled and each recognizer will recognize its pattern 
		   /// for each smartcandlestick in candlestick_List
		   /// </summary>
	protected: List<Candlestick^>^ candlesticksToSmartCandlesticks(List<Candlestick^>^) override;
		   /// <summary>
		   /// Overriding the function definition of stockDisplay_Form::candlesticksToSmartCandlesticks(List<Candlestick^>^)
		   /// such that when candlesticks are converted to smart candlesticks, they will call the list of recognizers to recognize all patterns
		   /// </summary>
	protected: System::Void loadData_OpenFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) override;
	};
}
