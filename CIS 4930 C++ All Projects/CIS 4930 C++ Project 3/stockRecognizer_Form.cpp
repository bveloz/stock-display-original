#include "pch.h"
#include "stockRecognizer_Form.h"

namespace CppCLRWinFormsProject {
	List<Recognizer^>^ stockRecognizer_Form::instantiateRecognizers(List<Recognizer^>^ lr) {
		if (lr == nullptr)
		{
			lr = gcnew List<Recognizer^>();
			//if list of recognizer is null initialize it. 	
			Recognizer^ temp = gcnew Recognizer_Peak();
			//temporary variable to create a recognizerPeak
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_Valley();
			//temporary variable to create a recognizerValley
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_Bearish();
			//temporary variable to create a recognizerBearish
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_Bullish();
			//temporary variable to create a recognizerBullish
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_BearishEngulfing();
			//temporary variable to create a recognizerBearishEngulfing
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_BearishHarami();
			//temporary variable to create a recognizerBearishHarami
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_BullishHarami();
			//temporary variable to create a recognizerBullishHarami
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_BullishEngulfing();
			//temporary variable to create a recognizerBullishEngulfing
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_Doji();
			//temporary variable to create a recognizerDoji
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_DragonflyDoji();
			//temporary variable to create a recognizerDragonflyDoji
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_GravestoneDoji();
			//temporary variable to create a recognizerGravestoneDoji
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_Hammer();
			//temporary variable to create a recognizerHammer
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_InvertedHammer();
			//temporary variable to create a recognizerInvertedHammer
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_Marubozu();
			//temporary variable to create a recognizerMarubozu
			lr->Add(temp);
			//add recognizer_peak to list
			temp = gcnew Recognizer_Neutral();
			//temporary variable to create a recognizerNeutral
			lr->Add(temp);
			//add recognizer_peak to list
		}
		return lr;
		//return list
	}
	System::Void stockRecognizer_Form::instantiateRecognizers() {
		this->recognizerList = instantiateRecognizers(this->recognizerList);
		//set the forms recognizer list to the result of instantiateRecognizers defined above
	}
	List<SmartCandlestick^>^ stockRecognizer_Form::callAllRecognizers(List<SmartCandlestick^>^ smartCsList) {
		instantiateRecognizers();
		//call instantiateRecognizers
		for each (Recognizer ^ r in recognizerList) r->recognizeAll(smartCsList);
		//recognize all of the patterns using recognizers for smartCsList
		return smartCsList;
	}
	List<Candlestick^>^ stockRecognizer_Form::candlesticksToSmartCandlesticks(List<Candlestick^>^ csList) {
		List<Candlestick^>^ returnList = gcnew List<Candlestick^>(csList->Count);
		//allocate space for a returnList
		List<SmartCandlestick^>^ tempList = gcnew List<SmartCandlestick^>(csList->Count);
		for each (Candlestick ^ cs in csList)
		{
			SmartCandlestick^ smartCS = gcnew SmartCandlestick(cs);
			//call smartcandlestick constructor with candlestick as an arguement
			tempList->Add(smartCS);
			//add candlestick to returnList
		}
		callAllRecognizers(tempList);
		//call the callAllRecognizers function
		for each (SmartCandlestick ^ cs in tempList) returnList->Add(cs);
		//add candlestick in smart candlestick to returnList
		return returnList;
		//return list
	}
	System::Void stockRecognizer_Form::loadData_OpenFileDialog_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		formLoader();
		//call formLoader function
		this->primaryFormControlsRelocation();
		//relocate controls for primary form
		for (int i = 1; i < loadData_OpenFileDialog->FileNames->Length; i++)
		{
			stockRecognizer_Form^ secondaryForms = gcnew stockRecognizer_Form();
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
}