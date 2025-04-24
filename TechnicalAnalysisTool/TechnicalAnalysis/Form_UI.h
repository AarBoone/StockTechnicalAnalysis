#pragma once
#include "StockReader.h"
#include "PeakValley.h"
#include "Wave.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Summary for Form_UI
	/// </summary>
	public ref class Form_UI : public System::Windows::Forms::Form
	{
	public:
		Form_UI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	/// <summary>
	/// Function to create a for based on a filename and a start and end date
	/// This is the function that is called to draw child forms
	/// Since this is only used for child forms we want most of the controls to be invisble
	/// </summary>
	/// <param name="FileName"></param>
	/// <param name="startDate"></param>
	/// <param name="endDate"></param>
	public: Form_UI(String^ FileName, DateTime startDate, DateTime endDate)
	{
		InitializeComponent();
		Text = FileName;

		candlesticks = StockReader::ReadFromCSV(FileName);
		filteredCandlesticks = FilterCandlesticks(candlesticks, startDate, endDate);

		DrawChart();
	}
	public: List<Candlestick^>^ filteredCandlesticks;
	private: System::Windows::Forms::Button^ button_UpdateData;
	public:
	public:	List<Candlestick^>^ candlesticks;
	private: System::Windows::Forms::CheckBox^ checkBox_isChild;

	public: List<PeakValley^>^ peaks = gcnew List<PeakValley^>(); // peaks margin m
	public: List<PeakValley^>^ allPeaks = gcnew List<PeakValley^>(); // peaks margin 1
	public: List<PeakValley^>^ valleys = gcnew List<PeakValley^>(); //valleys margin m
	public: List<PeakValley^>^ allValleys = gcnew List<PeakValley^>(); // valleys margin 1

	private: List<Wave^>^ upWaves = gcnew List<Wave^>();
	private: List<Wave^>^ downWaves = gcnew List<Wave^>();


	private: System::Windows::Forms::HScrollBar^ hScrollBar_Margin;
	private: System::Windows::Forms::Label^ label_Margin;
	private: System::Windows::Forms::ComboBox^ comboBox_upWaves;
	private: System::Windows::Forms::ComboBox^ comboBox_downWaves;
	private: System::Windows::Forms::Label^ label_upWaves;
	private: System::Windows::Forms::Label^ label_downWaves;
	private: System::Windows::Forms::CheckBox^ checkBox_ToggleAnnotations;
	private: System::Windows::Forms::Button^ button_Debug; // Button that when clicked enters a debug breakpoint 

	// P3
	PointF rectStart, rectEnd;
	double rectEndY;
	double rectEndX;
	double range;
	double minPrice, maxPrice;
	int stepCount;
	int confirmations;
	bool isDragging, rectStart_isPeak, isDrawn;
	bool isSimulating = false;
	PeakValley^ PVstart;
	private: System::Windows::Forms::Label^ label_WaveIsValid;

	private: List<double>^ fibonacci_levels = gcnew List<double>();
	private: System::Windows::Forms::Button^ button_IncUp;
	private: System::Windows::Forms::Button^ button_IncDown;
	private: System::Windows::Forms::Timer^ timer_Simulation;
	private: System::Windows::Forms::Label^ label_Range;
	private: System::Windows::Forms::Button^ button_Simulate;

	private:
		System::Collections::Generic::List<Form_UI^>^ childForms = gcnew System::Collections::Generic::List<Form_UI^>();

	

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_UI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_LoadStock;
	protected:

	protected:
	private: System::Windows::Forms::Button^ button_SelectStock;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_startDate;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_endDate;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_LoadTicker;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::ComponentModel::IContainer^ components;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->openFileDialog_LoadStock = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button_SelectStock = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker_startDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_endDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->chart_LoadTicker = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button_UpdateData = (gcnew System::Windows::Forms::Button());
			this->checkBox_isChild = (gcnew System::Windows::Forms::CheckBox());
			this->hScrollBar_Margin = (gcnew System::Windows::Forms::HScrollBar());
			this->label_Margin = (gcnew System::Windows::Forms::Label());
			this->comboBox_upWaves = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox_downWaves = (gcnew System::Windows::Forms::ComboBox());
			this->label_upWaves = (gcnew System::Windows::Forms::Label());
			this->label_downWaves = (gcnew System::Windows::Forms::Label());
			this->checkBox_ToggleAnnotations = (gcnew System::Windows::Forms::CheckBox());
			this->button_Debug = (gcnew System::Windows::Forms::Button());
			this->label_WaveIsValid = (gcnew System::Windows::Forms::Label());
			this->button_IncUp = (gcnew System::Windows::Forms::Button());
			this->button_IncDown = (gcnew System::Windows::Forms::Button());
			this->timer_Simulation = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_Range = (gcnew System::Windows::Forms::Label());
			this->button_Simulate = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_LoadTicker))->BeginInit();
			this->SuspendLayout();
			// 
			// openFileDialog_LoadStock
			// 
			this->openFileDialog_LoadStock->FileName = L"\"ABBV-Day.csv\"";
			this->openFileDialog_LoadStock->Multiselect = true;
			this->openFileDialog_LoadStock->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form_UI::openFileDialog_LoadStock_FileOk);
			// 
			// button_SelectStock
			// 
			this->button_SelectStock->Location = System::Drawing::Point(424, 536);
			this->button_SelectStock->Name = L"button_SelectStock";
			this->button_SelectStock->Size = System::Drawing::Size(120, 38);
			this->button_SelectStock->TabIndex = 0;
			this->button_SelectStock->Text = L"Select Stock(s)";
			this->button_SelectStock->UseVisualStyleBackColor = true;
			this->button_SelectStock->Click += gcnew System::EventHandler(this, &Form_UI::button_SelectStock_Click);
			// 
			// dateTimePicker_startDate
			// 
			this->dateTimePicker_startDate->Location = System::Drawing::Point(12, 517);
			this->dateTimePicker_startDate->Name = L"dateTimePicker_startDate";
			this->dateTimePicker_startDate->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_startDate->TabIndex = 1;
			this->dateTimePicker_startDate->Value = System::DateTime(2024, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_endDate
			// 
			this->dateTimePicker_endDate->Location = System::Drawing::Point(12, 558);
			this->dateTimePicker_endDate->Name = L"dateTimePicker_endDate";
			this->dateTimePicker_endDate->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker_endDate->TabIndex = 2;
			this->dateTimePicker_endDate->Value = System::DateTime(2024, 12, 31, 0, 0, 0, 0);
			// 
			// chart_LoadTicker
			// 
			chartArea1->Name = L"ChartArea_OHLC";
			chartArea1->Position->Auto = false;
			chartArea1->Position->Height = 70;
			chartArea1->Position->Width = 94;
			chartArea1->Position->X = 3;
			chartArea1->Position->Y = 4;
			chartArea2->AlignWithChartArea = L"ChartArea_OHLC";
			chartArea2->Name = L"ChartArea_Volume";
			chartArea2->Position->Auto = false;
			chartArea2->Position->Height = 25;
			chartArea2->Position->Width = 94;
			chartArea2->Position->X = 3;
			chartArea2->Position->Y = 75;
			this->chart_LoadTicker->ChartAreas->Add(chartArea1);
			this->chart_LoadTicker->ChartAreas->Add(chartArea2);
			this->chart_LoadTicker->Dock = System::Windows::Forms::DockStyle::Top;
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart_LoadTicker->Legends->Add(legend1);
			this->chart_LoadTicker->Location = System::Drawing::Point(0, 0);
			this->chart_LoadTicker->Name = L"chart_LoadTicker";
			series1->ChartArea = L"ChartArea_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=LimeGreen";
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Series_OHLC";
			series1->XValueMember = L"Date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series1->YValueMembers = L"High,Low,Open,Close";
			series1->YValuesPerPoint = 4;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->ChartArea = L"ChartArea_Volume";
			series2->IsXValueIndexed = true;
			series2->Legend = L"Legend1";
			series2->Name = L"Series_Volume";
			series2->XValueMember = L"Date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series2->YValueMembers = L"Volume";
			this->chart_LoadTicker->Series->Add(series1);
			this->chart_LoadTicker->Series->Add(series2);
			this->chart_LoadTicker->Size = System::Drawing::Size(1184, 511);
			this->chart_LoadTicker->TabIndex = 3;
			this->chart_LoadTicker->Text = L"CandlesticksVolume";
			this->chart_LoadTicker->Visible = false;
			this->chart_LoadTicker->PostPaint += gcnew System::EventHandler<System::Windows::Forms::DataVisualization::Charting::ChartPaintEventArgs^ >(this, &Form_UI::chart_LoadTicker_PostPaint);
			this->chart_LoadTicker->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form_UI::chart_LoadTicker_MouseDown);
			this->chart_LoadTicker->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form_UI::chart_LoadTicker_MouseMove);
			this->chart_LoadTicker->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form_UI::chart_LoadTicker_MouseUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(218, 523);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Start Date";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(221, 564);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"End Date";
			// 
			// button_UpdateData
			// 
			this->button_UpdateData->Location = System::Drawing::Point(654, 536);
			this->button_UpdateData->Name = L"button_UpdateData";
			this->button_UpdateData->Size = System::Drawing::Size(124, 38);
			this->button_UpdateData->TabIndex = 6;
			this->button_UpdateData->Text = L"Update Data";
			this->button_UpdateData->UseVisualStyleBackColor = true;
			this->button_UpdateData->Visible = false;
			this->button_UpdateData->Click += gcnew System::EventHandler(this, &Form_UI::button_UpdateData_Click);
			// 
			// checkBox_isChild
			// 
			this->checkBox_isChild->AutoSize = true;
			this->checkBox_isChild->Location = System::Drawing::Point(909, 0);
			this->checkBox_isChild->Name = L"checkBox_isChild";
			this->checkBox_isChild->Size = System::Drawing::Size(15, 14);
			this->checkBox_isChild->TabIndex = 7;
			this->checkBox_isChild->UseVisualStyleBackColor = true;
			this->checkBox_isChild->Visible = false;
			// 
			// hScrollBar_Margin
			// 
			this->hScrollBar_Margin->LargeChange = 3;
			this->hScrollBar_Margin->Location = System::Drawing::Point(909, 536);
			this->hScrollBar_Margin->Maximum = 20;
			this->hScrollBar_Margin->Minimum = 1;
			this->hScrollBar_Margin->Name = L"hScrollBar_Margin";
			this->hScrollBar_Margin->Size = System::Drawing::Size(243, 19);
			this->hScrollBar_Margin->TabIndex = 11;
			this->hScrollBar_Margin->Value = 1;
			this->hScrollBar_Margin->Visible = false;
			this->hScrollBar_Margin->ValueChanged += gcnew System::EventHandler(this, &Form_UI::hScrollBar_Margin_ValueChanged);
			// 
			// label_Margin
			// 
			this->label_Margin->AutoSize = true;
			this->label_Margin->Location = System::Drawing::Point(839, 536);
			this->label_Margin->Name = L"label_Margin";
			this->label_Margin->Size = System::Drawing::Size(51, 13);
			this->label_Margin->TabIndex = 12;
			this->label_Margin->Text = L"Margin: 1";
			this->label_Margin->Visible = false;
			// 
			// comboBox_upWaves
			// 
			this->comboBox_upWaves->FormattingEnabled = true;
			this->comboBox_upWaves->Location = System::Drawing::Point(92, 601);
			this->comboBox_upWaves->Name = L"comboBox_upWaves";
			this->comboBox_upWaves->Size = System::Drawing::Size(169, 21);
			this->comboBox_upWaves->TabIndex = 13;
			this->comboBox_upWaves->Text = L"Start Date ------- End Date";
			this->comboBox_upWaves->Visible = false;
			this->comboBox_upWaves->SelectedIndexChanged += gcnew System::EventHandler(this, &Form_UI::comboBox_upWaves_SelectedIndexChanged);
			// 
			// comboBox_downWaves
			// 
			this->comboBox_downWaves->FormattingEnabled = true;
			this->comboBox_downWaves->Location = System::Drawing::Point(388, 601);
			this->comboBox_downWaves->Name = L"comboBox_downWaves";
			this->comboBox_downWaves->Size = System::Drawing::Size(173, 21);
			this->comboBox_downWaves->TabIndex = 14;
			this->comboBox_downWaves->Text = L"Start Date ------- End Date";
			this->comboBox_downWaves->Visible = false;
			this->comboBox_downWaves->SelectedIndexChanged += gcnew System::EventHandler(this, &Form_UI::comboBox_downWaves_SelectedIndexChanged);
			// 
			// label_upWaves
			// 
			this->label_upWaves->AutoSize = true;
			this->label_upWaves->Location = System::Drawing::Point(12, 604);
			this->label_upWaves->Name = L"label_upWaves";
			this->label_upWaves->Size = System::Drawing::Size(74, 13);
			this->label_upWaves->TabIndex = 15;
			this->label_upWaves->Text = L"Bullish Waves";
			this->label_upWaves->Visible = false;
			// 
			// label_downWaves
			// 
			this->label_downWaves->AutoSize = true;
			this->label_downWaves->Location = System::Drawing::Point(303, 604);
			this->label_downWaves->Name = L"label_downWaves";
			this->label_downWaves->Size = System::Drawing::Size(79, 13);
			this->label_downWaves->TabIndex = 16;
			this->label_downWaves->Text = L"Bearish Waves";
			this->label_downWaves->Visible = false;
			// 
			// checkBox_ToggleAnnotations
			// 
			this->checkBox_ToggleAnnotations->AutoSize = true;
			this->checkBox_ToggleAnnotations->Location = System::Drawing::Point(1055, 607);
			this->checkBox_ToggleAnnotations->Name = L"checkBox_ToggleAnnotations";
			this->checkBox_ToggleAnnotations->Size = System::Drawing::Size(107, 17);
			this->checkBox_ToggleAnnotations->TabIndex = 17;
			this->checkBox_ToggleAnnotations->Text = L"Hide Annotations";
			this->checkBox_ToggleAnnotations->UseVisualStyleBackColor = true;
			this->checkBox_ToggleAnnotations->CheckedChanged += gcnew System::EventHandler(this, &Form_UI::checkBox_ToggleAnnotations_CheckedChanged);
			// 
			// button_Debug
			// 
			this->button_Debug->Location = System::Drawing::Point(561, 536);
			this->button_Debug->Name = L"button_Debug";
			this->button_Debug->Size = System::Drawing::Size(75, 23);
			this->button_Debug->TabIndex = 18;
			this->button_Debug->Text = L"Debug";
			this->button_Debug->UseVisualStyleBackColor = true;
			this->button_Debug->Visible = false;
			this->button_Debug->Click += gcnew System::EventHandler(this, &Form_UI::button_Debug_Click);
			// 
			// label_WaveIsValid
			// 
			this->label_WaveIsValid->AutoSize = true;
			this->label_WaveIsValid->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_WaveIsValid->Location = System::Drawing::Point(837, 564);
			this->label_WaveIsValid->Name = L"label_WaveIsValid";
			this->label_WaveIsValid->Size = System::Drawing::Size(53, 20);
			this->label_WaveIsValid->TabIndex = 19;
			this->label_WaveIsValid->Text = L"Wave:";
			this->label_WaveIsValid->Visible = false;
			// 
			// button_IncUp
			// 
			this->button_IncUp->Location = System::Drawing::Point(820, 603);
			this->button_IncUp->Name = L"button_IncUp";
			this->button_IncUp->Size = System::Drawing::Size(28, 23);
			this->button_IncUp->TabIndex = 20;
			this->button_IncUp->Text = L"+";
			this->button_IncUp->UseVisualStyleBackColor = true;
			this->button_IncUp->Visible = false;
			this->button_IncUp->Click += gcnew System::EventHandler(this, &Form_UI::button_IncUp_Click);
			// 
			// button_IncDown
			// 
			this->button_IncDown->Location = System::Drawing::Point(854, 603);
			this->button_IncDown->Name = L"button_IncDown";
			this->button_IncDown->Size = System::Drawing::Size(28, 23);
			this->button_IncDown->TabIndex = 21;
			this->button_IncDown->Text = L"-";
			this->button_IncDown->UseVisualStyleBackColor = true;
			this->button_IncDown->Visible = false;
			this->button_IncDown->Click += gcnew System::EventHandler(this, &Form_UI::button_IncDown_Click);
			// 
			// timer_Simulation
			// 
			this->timer_Simulation->Interval = 500;
			this->timer_Simulation->Tick += gcnew System::EventHandler(this, &Form_UI::timer_Simulation_Tick);
			// 
			// label_Range
			// 
			this->label_Range->AutoSize = true;
			this->label_Range->Location = System::Drawing::Point(779, 608);
			this->label_Range->Name = L"label_Range";
			this->label_Range->Size = System::Drawing::Size(39, 13);
			this->label_Range->TabIndex = 22;
			this->label_Range->Text = L"Range";
			this->label_Range->Visible = false;
			// 
			// button_Simulate
			// 
			this->button_Simulate->Location = System::Drawing::Point(888, 603);
			this->button_Simulate->Name = L"button_Simulate";
			this->button_Simulate->Size = System::Drawing::Size(139, 23);
			this->button_Simulate->TabIndex = 23;
			this->button_Simulate->Text = L"Start Simulation";
			this->button_Simulate->UseVisualStyleBackColor = true;
			this->button_Simulate->Visible = false;
			this->button_Simulate->Click += gcnew System::EventHandler(this, &Form_UI::button_Simulate_Click);
			// 
			// Form_UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 636);
			this->Controls->Add(this->button_Simulate);
			this->Controls->Add(this->label_Range);
			this->Controls->Add(this->button_IncDown);
			this->Controls->Add(this->button_IncUp);
			this->Controls->Add(this->label_WaveIsValid);
			this->Controls->Add(this->button_Debug);
			this->Controls->Add(this->checkBox_ToggleAnnotations);
			this->Controls->Add(this->label_downWaves);
			this->Controls->Add(this->label_upWaves);
			this->Controls->Add(this->comboBox_downWaves);
			this->Controls->Add(this->comboBox_upWaves);
			this->Controls->Add(this->label_Margin);
			this->Controls->Add(this->hScrollBar_Margin);
			this->Controls->Add(this->checkBox_isChild);
			this->Controls->Add(this->button_UpdateData);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart_LoadTicker);
			this->Controls->Add(this->dateTimePicker_endDate);
			this->Controls->Add(this->dateTimePicker_startDate);
			this->Controls->Add(this->button_SelectStock);
			this->Name = L"Form_UI";
			this->Text = L"Form_UI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_LoadTicker))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/// <summary>
	/// Event handler for the select a stock button
	/// Calls the openFileDialog
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void button_SelectStock_Click(System::Object^ sender, System::EventArgs^ e) {
		// Show the open file dialog
		openFileDialog_LoadStock->ShowDialog();
		button_SelectStock->Text = "Select New Stock(s)";
	}

	/// <summary>
	/// Event handler for when file(s) selected
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void openFileDialog_LoadStock_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		
		String^ fn = System::IO::Path::GetFileName(openFileDialog_LoadStock->FileName);
		Text = fn;
		chart_LoadTicker->Titles->Clear();
		chart_LoadTicker->Titles->Add(fn);
		
		DrawChildForms();

		candlesticks = StockReader::ReadFromCSV(openFileDialog_LoadStock->FileNames[0]); // Read all the candlesticks from the first (possibly only) selected CSV
		filteredCandlesticks = FilterCandlesticks(candlesticks, dateTimePicker_startDate->Value, dateTimePicker_endDate->Value);

		DrawChart();
		if (checkBox_isChild->Checked == false) // If the form is not a child form (will only be true of the super-parent)
		{
			button_UpdateData->Visible = true; // Show the Update Button
		}

		while (0); // Debugging Breakpoint
	}

	// Given a list of candlesticks create a new list with only the candlesticks between the start and end dates
	public: List<Candlestick^>^ FilterCandlesticks(List<Candlestick^>^ listOfCandles, DateTime startDate, DateTime endDate) 
	{


		// Create a new list of candlesticks to store the filtered data
		filteredCandlesticks = gcnew List<Candlestick^>();

		// Go through the array of all candlesticks
		for (int i = 0; i < (listOfCandles->Count) && listOfCandles[i]->Date < endDate; i++) 
		{
			//If the date of the candlestick is between the selected start and end date add it to the filtered list
			DateTime temp = listOfCandles[i]->Date;
			if ((temp >= startDate) && (temp <= endDate)) 
			{
				filteredCandlesticks->Add(listOfCandles[i]);
			}
		}

		// Return the filtered candlesticks list
		return filteredCandlesticks;
	}

	/// <summary>
	/// Function to Draw the chart by:
	/// creating a bindingList and binding the data to the viewers
	/// Calls Normalize to normalize the chart
	/// </summary>
	public: void DrawChart()
	{
		// Clear old annotations and peaks and valleys
		chart_LoadTicker->Annotations->Clear();
		peaks->Clear();
		valleys->Clear();
		
		//Create a binding list based on the filtered candlesticks
		BindingList<Candlestick^>^ bindingList = gcnew BindingList<Candlestick^>(filteredCandlesticks);


		//Bind the bindingList to the chart
		this->chart_LoadTicker->DataSource = bindingList;
		this->chart_LoadTicker->DataBind();

		//Call the normalize chart functon
		NormalizeChart();
		

		// Find Peaks and Valleys of form and store them in the forms peaks and valleys lists respectively
		FindPeaks(filteredCandlesticks);
		FilterPeaks(hScrollBar_Margin->Value);
		FindValleys(filteredCandlesticks);
		FilterValleys(hScrollBar_Margin->Value);

		
		
		CalculateValidWaves();

		if (checkBox_ToggleAnnotations->Checked == false) { DrawAllAnnotations(); }
		chart_LoadTicker->Refresh();



		// Make sure that the chart and margin controls are visible
		this->chart_LoadTicker->Visible = true;
		this->hScrollBar_Margin->Visible = true;
		this->label_Margin->Visible = true;

	} // End of DrawChart function

	/// <summary>
	/// Void Function to Normalize the chart by finding the min and max of the filtered candlesticks
	/// </summary>
	public: void NormalizeChart() 
	{
		// Min and max to keep track of these
		double max = 0;
		double min = INFINITY;

		// Go through all the filtered candlesticks and find the min and max
		for (int i = 0; i < filteredCandlesticks->Count; i++) 
		{
			if (filteredCandlesticks[i]->High > max) max = filteredCandlesticks[i]->High;
			if (filteredCandlesticks[i]->Low < min) min = filteredCandlesticks[i]->Low;
		}

		// Set the padding to be 2% 
		double padding = (max - min) * 0.1;

		//Normalize the Yaxis of the Chart Areas
		chart_LoadTicker->ChartAreas[0]->AxisY->Minimum = (min - padding);
		chart_LoadTicker->ChartAreas[0]->AxisY->Maximum = max + padding;

		// Format the Yaxis to 2 decimal places
		chart_LoadTicker->ChartAreas[0]->AxisY->LabelStyle->Format = "0.00";
	}// End of NormalizeChart function

	// ----------------------------------------------------------------- Project 2 ------------------------------------------------------------------------------------------

	/// <summary>
	/// Event handler for when the update button is clicked
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void button_UpdateData_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dateTimePicker_startDate->Value >= dateTimePicker_endDate->Value) { MessageBox::Show("Invalid Date Range", "Message", MessageBoxButtons::OK, MessageBoxIcon::Information);  return; }
		filteredCandlesticks = FilterCandlesticks(this->candlesticks, dateTimePicker_startDate->Value, dateTimePicker_endDate->Value); // refilter candlesticks
		DrawChart(); // redraw the chart
	}

	/// <summary>
	/// Function to draw child forms when multiple stocks are selected
	/// </summary>
	private: void DrawChildForms() 
	{
		// Iterate through all fileName in fileNames
		for (int i = 1; i < openFileDialog_LoadStock->FileNames->Length; i++)
		{
			// Create a new Form_UI based on filename i
			String^ fp = openFileDialog_LoadStock->FileNames[i]; // get filepath i
			String^ filename = System::IO::Path::GetFileName(fp); // get the filename at the end of the filepath
			Form_UI^ newform = gcnew Form_UI(fp, dateTimePicker_startDate->Value, dateTimePicker_endDate->Value); // call the Form_UI contructor with the filepath, start and end dates
			newform->Show(); // Show that child form
			newform->Text = filename; // Set the text of the child form to be the file name
			newform->chart_LoadTicker->Titles->Clear(); // clear the titles of the form so we can write a new one
			newform->chart_LoadTicker->Titles->Add(filename); // Change the title to be the filename
			newform->button_UpdateData->Visible = true;
		}
	} // End of DrawChildForms



	
/// <summary>
/// Finds all peaks margin 1
/// </summary>
/// <param name="fC"></param>
private: void FindPeaks(List<Candlestick^>^ fC) // Recalculates all peaks of index 1
	{
		allPeaks->Clear(); // Clear all the old peaks (so we dont get duplicates)
		for (int i = 1; i < ((fC->Count) - 1); i++) { // for each candlestick check if its a peak
			if (fC[i]->High > fC[i - 1]->High && fC[i]->High > fC[i + 1]->High) // If the candlesticks j to the left and right of i fit criterea of peak
			{
				PeakValley^ newPeak = gcnew PeakValley(fC[i], i, /*isPeak =*/ true); // create a new Peak of index i
				allPeaks->Add(newPeak); // add it to the list of peaks
			}

			for each (PeakValley ^ peak in allPeaks) \
			{
				SetMarginOf(peak); // call SetMarginOf for each peak
				
			}
		}
	} // End of FindPeaks

	/// <summary>
	/// Function to fill allValleys array with valleys margin 1
	/// </summary>
	/// <param name="fC"></param>
	private: void FindValleys(List<Candlestick^>^ fC)
	{
		allValleys->Clear(); // Clear the old valleys list (so we dont get duplicates)
		// Go through all candlesticks starting at index m and stopping m before the last and find all candlesticks of margin m
		for (int i = 1; i < ((fC->Count) - 1 ); i++) {
			if (fC[i]->Low < fC[i - 1]->Low && fC[i]->Low < fC[i + 1]->Low) // If the candlesticks j to the left and right of i fit criterea of valley
			{
				PeakValley^ newValley = gcnew PeakValley(fC[i], i, /*isPeak =*/ false); // create a new PeakValley of index i
				allValleys->Add(newValley); // add it to the list of valleys
			}
			for each (PeakValley ^ val in allValleys) 
			{
				SetMarginOf(val); // call SetMarginOf for each valley
			}
		}
	} // End of FindValleys

	/// <summary>
	/// Given a PeakValley this function calculates its margin by going left and right until it hits something that would cause it to no longer be a peak/valley
	/// </summary>
	/// <param name="apex"></param>
	private: void SetMarginOf(PeakValley^ apex) 
	{
		bool p = apex->IsPeak;
		int startIndex = apex->Index;
		int l = startIndex - 1;
		int r = startIndex + 1;

		while (l >= 0 && r < filteredCandlesticks->Count) 
		{
			if (p) // If function is called on a peak
			{
				if (!(apex->Cs->High > filteredCandlesticks[l]->High && filteredCandlesticks[startIndex]->High > filteredCandlesticks[r]->High)) // if not a peak to the l and r pointers
				{
					l = -1; // set l to -1 to guarantee break from while loop
				}
				else // increment each pointer 1 step away from the PV
				{ 
					l--;
					r++;
				}
			}
			else // If function called on a valley 
			{ 
				if (!(filteredCandlesticks[startIndex]->Low < filteredCandlesticks[l]->Low && filteredCandlesticks[startIndex]->Low < filteredCandlesticks[r]->Low)) 
				{
					l = -1;
				}
				else // increment each pointer 1 step away from the PV
				{
					l--;
					r++;
				}
			}
			apex->Margin = r - startIndex - 1; // set the margin of apex to be the distance between r and startIndex (-1 because it failed on this r)
		}
	}// End of SetPVMargin


	/// <summary>
	/// Function to filter allpeaks and fill array peaks with margin
	/// </summary>
	/// <param name="fC"></param>
	private: void FilterPeaks(int margin) 
	{
		peaks->Clear(); // Clear all the old peaks (so we dont get duplicates)
		
		for each (PeakValley ^ peak in allPeaks) 
		{
			if (peak->Margin >= margin) { peaks->Add(peak); }
		}
	} // End of FilterPeaks

	/// <summary>
	/// Function that goes through array allValleys and filters down to just an array of val->margin > margin
	/// </summary>
	/// <param name="margin"></param>
	private: void FilterValleys(int margin)
	{
		valleys->Clear(); // Clear all the old peaks (so we dont get duplicates)

		for each (PeakValley ^ val in allValleys)
		{
			if (val->Margin >= margin) { valleys->Add(val); }
		}
	} // End of FilterValleys
	
	private: void DrawArrow(PeakValley^ PV) 
	{
		// Check if PeakValley obj is a peak or a valley
		bool isPeak = PV->IsPeak;
		ArrowAnnotation^ arrow = gcnew ArrowAnnotation();

		int index = PV->Index;

		arrow->AnchorDataPoint = chart_LoadTicker->Series["Series_OHLC"]->Points[index];
		arrow->ArrowStyle = ArrowStyle::Simple;
		arrow->ArrowSize = 3;
		arrow->Width = 1; // Width of the arrow
		arrow->Tag = "PV";

		// if arrow is peak set height to negative (so it points down) and set color to green
		if (isPeak) { arrow->Height = -2; arrow->BackColor = Color::LimeGreen; }

		// else its a valley so set height to 2 and color to red
		else { 
			arrow->Height = 2; 
			arrow->BackColor = Color::Red; 
			// if called with a valley then we want to anchor the arrow to the bottom of the candlestick
			arrow->Y = chart_LoadTicker->Series["Series_OHLC"]->Points[index]->YValues[1];
		}

		chart_LoadTicker->Annotations->Add(arrow);
	}

	

	/// <summary>
	/// Redraws this->form peak and valley annotations
	/// </summary>
	private: void AnnotatePeaksAndValleys() 
	{
		chart_LoadTicker->Annotations->Clear(); // Clear old peak and valley annotations

		for each (PeakValley ^ peak in peaks) // For each peak, create an arrow annotation for it
		{
			DrawArrow(peak); // Call Draw arrow with the current peak
		}

		for each (PeakValley ^ valley in valleys) // For each valley create an annotation for it
		{
			DrawArrow(valley); // Call draw arrow with the current valley
		}

		chart_LoadTicker->Update(); // Force update the chart just in case
	} // End of AnnotatePeaksAndValleys

	/// <summary>
	/// Event handler for when the hScrollBar changes value
	/// Calls the update margin function to be the new value
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void hScrollBar_Margin_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		int margin = hScrollBar_Margin->Value; // Set the margin to the value of the scroll bar
		String^ marString = "Margin:" + margin.ToString(); // Convert that value to a string
		label_Margin->Text = marString; // Display the margin as text
		UpdateMargin(margin); // Call update margin using new margin
	} 

	/// <summary>
	/// Updates the margin of the given form
	/// </summary>
	/// <param name="margin"></param>
	private: void UpdateMargin(int margin) 
	{
		FilterPeaks(margin); // Find peaks of new margin
		FilterValleys(margin); // Find valleys of new margin
		CalculateValidWaves(); // Calculate all valid waves (this function calls the populate comboboxes as well)
		if (checkBox_ToggleAnnotations->Checked == false) { // If the toggle annotations box is not checked
			DrawAllAnnotations(); // then redraw annotations of new margin
		}

	} // End of UpdateMargin

	/// <summary>
	/// Calculates all valid up and down waves and populates the respective comboboxes with the results
	/// </summary>
	private: void CalculateValidWaves() 
	{
		downWaves->Clear(); // Delete Old Waves
		upWaves->Clear();

		CalculateValidUpWaves(); // Calculate New Waves
		CalculateValidDownWaves();

		PopulateWavesComboboxes(); // Put the new waves in the comboboxes

		while (0) {} // Debugging breakpoint
	} // end of CalculateValidWaves

	private: void CalculateValidUpWaves() 
	{
		for (int i = 0; i < valleys->Count; i++) 
		{
			int currIndex = valleys[i]->Index;
			int indexOfLowBelowCurr = i;
			double low = NULL;
			double high = NULL;

			for (int j = i; j < valleys->Count; j++) // Find the next valley below the current valley
			{
				if (Wave::isBelow(valleys[i], valleys[j])){ // If v[j]->Low is less than v[i]->Low then all valid waves starting at v[i] must occur between v[i]->Index and v[j]->Index 
					indexOfLowBelowCurr = valleys[j]->Index;
					break;
				}
				if (j + 1 == valleys->Count) // if j is about to be out of bounds 
				{ 
					indexOfLowBelowCurr = filteredCandlesticks->Count; // then set the final index to be the last candlestick
					low = valleys[i]->Cs->Low; // Set the high and low values for calculating valid waves
					high = valleys[i]->Cs->High;
					break;  
				} 
				low = valleys[i]->Cs->Low; // Set the high and low values for calculating valid waves
				high = valleys[i]->Cs->High;

			} // Break jumps to here - At this point valleys[i]->Index and indexOfLowBelowCurr bound all possible waves starting at valleys[i]

			
			// Find all peaks in range and check if they make a valid wave
			for (int j = 0; j < peaks->Count; j++) 
			{
				if (peaks[j]->Index > currIndex && peaks[j]->Index <= indexOfLowBelowCurr) // If the index of peak[j] is in our bounds, check if it makes valid wave
				{ 
					if (peaks[j]->Cs->Low < low) { break; } // If this peaks low is below our starting low its impossible for any candlestick after this one to make a valid wave so we can break

					if (peaks[j]->Cs->High >= high) // if this peaks high is above previous high then it is a valid wave
					{
						// Make a new wave and add it to the upWaves list
						Wave^ newWave = gcnew Wave(valleys[i]->Index, peaks[j]->Index);
						upWaves->Add(newWave);
						// Update the high for validity calculations
						high = peaks[j]->Cs->High;
					}
				}
			}
		}
	} // End of CalculateValidUpWaves

	private: void CalculateValidDownWaves() 
	{
		for (int i = 0; i < peaks->Count; i++)
		{
			int currIndex = peaks[i]->Index;
			int indexOfHighAboveCurr = i;
			double low = NULL;
			double high = NULL;

			for (int j = i; j < peaks->Count; j++) // Find the next peak above the current peak
			{
				if (Wave::isAbove(peaks[i], peaks[j])) { // If j->Low is less than i->Low then all valid waves starting at peak[i] must occur between peak[i]->Index and peak[j]->Index 
					indexOfHighAboveCurr = peaks[j]->Index;
					break;
				}
				if (j + 1 == peaks->Count) // if j is about to be out of bounds
				{ 
					indexOfHighAboveCurr = filteredCandlesticks->Count; // then set the last valid index to be the end of the filtered candlesticks
					low = peaks[i]->Cs->Low; // Set our High and Low values for calculating valid waves
					high = peaks[i]->Cs->High;
					break; // and exit this iteration of the loop
				} 
				
				low = peaks[i]->Cs->Low; // Set our High and Low values for calculating valid waves
				high = peaks[i]->Cs->High;

			} // Break jumps to here - At this point peaks[i]->Index and indexOfHighAboveCurr bound all possible waves starting at valleys[i]
			// and low and high are set to the proper values for calculating waves


			// Find all valleys in range and check if they make a valid wave
			for (int j = 0; j < valleys->Count; j++)
			{
				if (valleys[j]->Index > currIndex && valleys[j]->Index <= indexOfHighAboveCurr) // If the index of peak[j] is in our bounds, check if it makes valid wave
				{
					if (valleys[j]->Cs->High > high) { break; } // IF this valleys high is higher than the start it will always break the rectangle so we can stop searching

					if (valleys[j]->Cs->Low <= low) // If this valleys low is lower than the previous low then it it a valid wave
					{
						// Create a new wave and add it to the downWaves
						Wave^ newWave = gcnew Wave(peaks[i]->Index, valleys[j]->Index);
						downWaves->Add(newWave);
						// Update the low to the be the new low
						low = valleys[j]->Cs->Low;
					}
				}
			}
		}
	} // End of CalulateValidDownWaves

	private: void PopulateWavesComboboxes() 
	{
		// Make wave selector components visible
		comboBox_downWaves->Visible = true;
		comboBox_upWaves->Visible = true;
		label_downWaves->Visible = true;
		label_upWaves->Visible = true;

		// Delete old options from comboboxes
		comboBox_downWaves->Items->Clear();
		comboBox_upWaves->Items->Clear();

		// Populate upWaves comboBox
		for each (Wave ^ wave in upWaves)
		{
			// Create a new string based on the start and end date
			String^ startDate = (filteredCandlesticks[wave->Start]->Date).ToString("MM/dd/yyyy");
			String^ endDate = (filteredCandlesticks[wave->End]->Date).ToString("MM/dd/yyyy");
			String^ forBox = startDate + "--------" + endDate;
			// Add that string to its respective comboBox
			comboBox_upWaves->Items->Add(forBox);
		}

		// Populate downWaves comboBox
		for each (Wave ^ wave in downWaves)
		{
			// Create a new string based on the start and end date
			String^ startDate = (filteredCandlesticks[wave->Start]->Date).ToString("MM/dd/yyyy");
			String^ endDate = (filteredCandlesticks[wave->End]->Date).ToString("MM/dd/yyyy");
			String^ forBox = startDate + "--------" + endDate;
			// Add that string to its respective comboBox
			comboBox_downWaves->Items->Add(forBox);
		}
	} // End of PopulateWavesComboboxes

	/// <summary>
	/// Function for when an upWave is selected using the comboBox
	/// Should mark the wave with a green line
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void comboBox_upWaves_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		
		RemoveAnnotaionsWithTag("UpWave");

		// Call function to draw the annotations on the wave
		if (checkBox_ToggleAnnotations->Checked == false) {
			DrawSelectedWave(1); // Call with 1 for upWave
		}
		}
	private: System::Void comboBox_downWaves_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		RemoveAnnotaionsWithTag("DownWave");

		if (checkBox_ToggleAnnotations->Checked == false){
			DrawSelectedWave(0); // Call with 0 for down wave
		}		
	}

	/// <summary>
	/// Event handler for the toggle annotations check box
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns></returns>
	private: System::Void checkBox_ToggleAnnotations_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (checkBox_ToggleAnnotations->Checked == true) { chart_LoadTicker->Annotations->Clear(); } // If the box is now checked clear the annotations
		if (checkBox_ToggleAnnotations->Checked == false) { DrawAllAnnotations(); } // if the box is now unchecked then redraw the annotations
	}

	/// <summary>
	/// Draws a wave
	/// I wanted to practice ternary operators so there are a lot of difficult to read lines here, but I clarified them with comments to the side
	/// I could rewrite the initialization part of the function as ternary's but i thought it was more readable this way
	/// </summary>
	/// <param name="upWave"> A bool to represent if this function is being called to draw an upwave or a downWave 1 = up 0 = down</param>
	private: void DrawSelectedWave(bool upWave) 
	{
		// Allocate the values we need to draw the rectangles and arrows
		int selectedIndex, startIndex, endIndex;
		double startX, endX, minY, maxY;

		ShowSimulationControls();

		// if (upWave) then selectedIndex = comboBox_upWaves->SelectedIndex else selectedIndex = downWaves->SelectedIndex
		(upWave) ? selectedIndex = comboBox_upWaves->SelectedIndex : selectedIndex = comboBox_downWaves->SelectedIndex;
		if (selectedIndex == -1) { return; } // If no item from this box is selected do nothing and return

		// Initialize the wave with necessary values
		if (upWave) // if this function was called for an upWave
		{
			startIndex = upWaves[selectedIndex]->Start; // Get the start and end indexes of the wave
			endIndex = upWaves[selectedIndex]->End;

			startX = startIndex + 1; //Index +1 set
			endX = endIndex + 1;
			minY = filteredCandlesticks[startIndex]->Low;
			maxY = filteredCandlesticks[endIndex]->High;
		}
		else // if this function was called for a downWave 
		{
			startIndex = downWaves[selectedIndex]->Start;
			endIndex = downWaves[selectedIndex]->End;

			startX = startIndex + 1; 
			endX = endIndex + 1;
			minY = filteredCandlesticks[endIndex]->Low;
			maxY = filteredCandlesticks[startIndex]->High;
		}


		// Im tempted to write a new Function for this but this is the only place in the code it exists so theres no need to abstract it away
		RectangleAnnotation^ rect = gcnew RectangleAnnotation();
		rect->AxisX = chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisX;
		rect->AxisY = chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY;
		rect->IsSizeAlwaysRelative = false;
		rect->ClipToChartArea = "ChartArea_OHLC";
		rect->X = startX;
		rect->Y = minY;
		rect->Width = endX - startX;
		rect->Height = maxY - minY;
		(upWave) ? rect->LineColor = Color::Green : rect->LineColor = Color::Red; // if (upWave) then LineColor = Green else LineColor = Red
		rect->LineWidth = 2;
		(upWave) ? rect->BackColor = Color::FromArgb(10, Color::LimeGreen) : rect->BackColor = Color::FromArgb(10, Color::Red);
		(upWave) ? rect->Tag = "UpWave" : rect->Tag = "DownWave"; // if (upWave) then Tag = "UpWave" else Tag = "DownWave"

		chart_LoadTicker->Annotations->Add(rect);

		// Diagonal Line
		LineAnnotation^ line = gcnew LineAnnotation();
		line->AxisX = chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisX;
		line->AxisY = chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY;
		line->IsSizeAlwaysRelative = false;
		line->ClipToChartArea = "ChartArea_OHLC";


		(upWave) ? line->X = startX :line->X = endX; // If (upWave) then line->X = startX else line->x = endX
		line->Y = minY;
		(upWave) ? line->Width = endX - startX : line->Width = startX - endX; // If the line is an upWave we need to draw the line in reverse 
		line->Height = maxY - minY;

		(upWave) ? line->LineColor = Color::LimeGreen : line->LineColor = Color::PaleVioletRed; // If (upWave) then lineColor = LimeGreen else lineColor = PaleVioletRed
		line->LineWidth = 2;
		(upWave) ? line->Tag = "UpWave" : line->Tag = "DownWave"; // if (upWave) then Tag = "UpWave" else Tag = "DownWave"

		chart_LoadTicker->Annotations->Add(line);
	}

	/// <summary>
	/// Function that is called anytime any annotation needs to be redrawn
	/// </summary>
	private: void DrawAllAnnotations() 
	{
		AnnotatePeaksAndValleys();
		DrawSelectedWave(1); // If an upWave is selected this will draw it
		DrawSelectedWave(0); // if a downWave is selected this will draw it
	}

	/// <summary>
	/// Function that goes through all child forms, checks if they were closed and if they were removes them from the childForms array
	/// Function is laid out like this because if we remove items from the list during iteration (like using a for each loop through all the child forms)
	/// it could mess with the iteration through the forms
	/// </summary>
	private: void RemoveClosedChildForms() 
	{
		List<int>^ indexesToRemove = gcnew List<int>(); // Create a list of ints to store indexes
		 
		for (int i = 0; i < childForms->Count; i++) // go through childForms by index
		{
			if (childForms[i]->IsDisposed) { indexesToRemove->Add(i); } // if the form has been closed add its index to array of indexesToRemove
		}

		indexesToRemove->Reverse(); // Reverse the array (now highest index first, prevents OOB errors)

		for each (int idx in indexesToRemove) // For each index to be removed
		{
			childForms->RemoveAt(idx); // remove it
		}
	}

	private: bool isValidWave(PeakValley^ start, int index, double yPos) 
	{
		double high = start->Cs->High;
		double low = start->Cs->Low;

		if (start->Index > index) { return false; }

		//Catch if the mouse is leaving the chart area
		if (index >= filteredCandlesticks->Count || index == 0) { return false; }

		if (start->IsPeak) {
			for (int i = start->Index; i < index - 1; i++) {
				if (filteredCandlesticks[i]->High > high) { return false; }
				if (filteredCandlesticks[i]->Low < low) { low = filteredCandlesticks[i]->Low; }
			}
			//if (low < filteredCandlesticks[index]->Low) { return false; }
			if (yPos > low) { return false; }
			else { return true; }
		}
		else {
			for (int i = start->Index; i < index - 1; i++) {
				if (filteredCandlesticks[i]->Low < low) { return false; }
				if (filteredCandlesticks[i]->High > high) { high = filteredCandlesticks[i]->High; }
			}
			if (yPos < high) { return false; }
			else { return true; }
		}
	}



/// <summary>
/// Theres a debug button. When you hit it, it enters this function and just goes to a breakpoint. Used to check peaks and valleys arrays
/// The button is invisible in the form, but i just make it visible when i want to use it
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void button_Debug_Click(System::Object^ sender, System::EventArgs^ e) 
{
	while (0); //Debugging breakpoint
}
// ------------------------------------------------------ project 3 --------------------------------------------------------------------------------

/// <summary>
/// Event handler for mouse down event
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void chart_LoadTicker_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	

	// Refilter peaks on mouse down just in case
	FilterPeaks(hScrollBar_Margin->Value);
	FilterValleys(hScrollBar_Margin->Value);

	// Turn the label to tell if wave is valid on
	label_WaveIsValid->Visible = true;
	isDrawn = false;

	// Show Controls for simulation
	ShowSimulationControls();

	// Get the value of the mouse click
	double mouseX = e->X;
	double mouseY = e->Y;
	rectStart_isPeak = false; // shouldnt need to reset this, but do it just in case

	// If there are no peaks or valleys (margin too big) then just exit without doing anything
	if (peaks->Count + valleys->Count == 0) { return; }

	// Populate the XY value of every peak and valley
	for each (PeakValley ^ peak in peaks) {
		if (peak->X == 0) { // If the peak doesnt have XY info add it
			peak->SetX(chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisX->ValueToPixelPosition(peak->Index+1));
			peak->SetY(chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY->ValueToPixelPosition(peak->Cs->High));
		}
	}

	for each (PeakValley ^ valley in valleys) {
		if (valley->X == 0) { // If the valley doesnt have XY info add it
			valley->SetX(chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisX->ValueToPixelPosition(valley->Index+1));
			valley->SetY(chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY->ValueToPixelPosition(valley->Cs->Low));
		}
	}


	int indexPeak = 0; 
	int indexVal = 0;
	double minDist_peak = std::numeric_limits<double>::max();
	double minDist_val = std::numeric_limits<double>::max();
	// Find closest peak to starting mouse position
	for each (PeakValley ^ peak in peaks) {
		double temp = Math::Sqrt(Math::Pow(mouseX - peak->X, 2) + Math::Pow(mouseY - peak->Y, 2));
		if (temp < minDist_peak) { 
			minDist_peak = temp; 
			indexPeak = peaks->IndexOf(peak); 
		}
	}
	

	//Find closest valley to starting mouse position
	for each (PeakValley ^ val in valleys) {
		double temp = Math::Sqrt(Math::Pow(mouseX - val->X, 2) + Math::Pow(mouseY - val->Y, 2));
		if (temp < minDist_val) { minDist_val = temp; indexVal = valleys->IndexOf(val); }
	}

	// Check if mouse is closer to peak or valley
	if (peaks->Count > 0) {
		minDist_peak = Math::Sqrt(Math::Pow(mouseX - peaks[indexPeak]->X, 2) + Math::Pow(mouseY - peaks[indexPeak]->Y, 2));
	}
	if (valleys->Count > 0) {
		minDist_val = Math::Sqrt(Math::Pow(mouseX - valleys[indexVal]->X, 2) + Math::Pow(mouseY - valleys[indexVal]->Y, 2));
	}

	// if closer to peak snap to that peak
	if (minDist_peak < minDist_val) {
		rectStart = PointF(peaks[indexPeak]->X, peaks[indexPeak]->Y);
		PVstart = peaks[indexPeak];
		rectStart_isPeak = true;
	}
	else { // else snap to the closest valley
		rectStart = PointF(valleys[indexVal]->X, valleys[indexVal]->Y);
		PVstart = valleys[indexVal];
		rectStart_isPeak = false;
	}

	isDragging = true; // set dragging flag to true
	chart_LoadTicker->Invalidate(); // invalidate the chart
}


private: System::Void chart_LoadTicker_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	if (isDragging) { // While dragging	

		
		auto ax = chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisX;
		auto ay = chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY;

		// Make sure the mouse position stays in the chart
		rectEndY = Math::Min(e->Y, 470);
		rectEndY = Math::Max(rectEndY, double(10));

		rectEndX = Math::Min(double(e->X), double(ax->ValueToPixelPosition(ax->Maximum)));
		rectEndX = Math::Max(rectEndX, double(ax->ValueToPixelPosition(ax->Minimum)));
		rectEnd = PointF((float)rectEndX, (float)rectEndY);

		chart_LoadTicker->Invalidate(); // trigger redraw	
	}
}
private: System::Void chart_LoadTicker_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	isDragging = false; // set dragging flag to false
	isDrawn = true; // set is drawn to true
	stepCount = 0; // reset step count for simulation
	(rectStart_isPeak) ? range = rectStart.Y - rectEnd.Y : range = rectEnd.Y - rectStart.Y; // calculate range for simulation
	range = range / 100;
	minPrice = rectEnd.Y - (range * 20); // calc min and max price for simulation 
	maxPrice = rectEnd.Y + (range * 20); // this allows simulation to wrap from high to low in one step
}


private: System::Void chart_LoadTicker_PostPaint(System::Object^ sender, System::Windows::Forms::DataVisualization::Charting::ChartPaintEventArgs^ e) {

	if (isDragging)
	{
		PaintEvent(e); //Paint the wave
	}
	if (isDrawn) {
		PaintEvent(e);
	}
	if (isSimulating) {
		PaintEvent(e);
	}
}

private: void PaintEvent(System::Windows::Forms::DataVisualization::Charting::ChartPaintEventArgs^ e) {
	//Clear old fibonacci levels
	fibonacci_levels->Clear();
	//Calculate the new fibonacci levels
	fibonacci_levels = GetFibonacciLevels(PVstart,
		chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisX->PixelPositionToValue(rectEnd.X),
		chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY->PixelPositionToValue(rectEnd.Y)
	);

	// Create a graphic for the chart
	Graphics^ g = e->ChartGraphics->Graphics;

	// Set x and y based on mouse position
	float x = Math::Min(rectStart.X, rectEnd.X);
	float y = Math::Min(rectStart.Y, rectEnd.Y);
	float width = Math::Abs(rectEnd.X - rectStart.X);
	float height = Math::Abs(rectEnd.Y - rectStart.Y);

	RectangleF rect = RectangleF(x, y, width, height);

	Pen^ outlinePen = gcnew Pen(Color::Blue, 1);
	outlinePen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dash;
	Pen^ diagonalLinePen = gcnew Pen(Color::LightBlue, 1);


	// If the mouse is on a peak draw rectangle
	if (rectStart_isPeak && (rectStart.Y < rectEnd.Y)) {
		g->DrawRectangle(outlinePen, rect.X, rect.Y, rect.Width, rect.Height);
		g->DrawLine(diagonalLinePen, rectStart, rectEnd);

		for (int i = 0; i < 7; i++) {
			Pen^ fibPen = gcnew Pen(Color::Pink, 1);
			fibPen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
			PointF^ start = gcnew PointF(x, chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY->ValueToPixelPosition(fibonacci_levels[i]));
			PointF^ end = gcnew PointF((x + width), chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY->ValueToPixelPosition(fibonacci_levels[i]));

			g->DrawLine(fibPen, start->X, start->Y, end->X, end->Y);
		}
	}

	//if mouse is on a valley draw rectangle differently
	if (!rectStart_isPeak && (rectStart.Y > rectEnd.Y)) {
		g->DrawRectangle(outlinePen, rect.X, rect.Y, rect.Width, rect.Height);
		g->DrawLine(diagonalLinePen, rectStart, rectEnd);

		for (int i = 0; i < 7; i++) {
			Pen^ fibPen = gcnew Pen(Color::Pink, 1);
			fibPen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
			PointF^ start = gcnew PointF(x, chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY->ValueToPixelPosition(fibonacci_levels[i]));
			PointF^ end = gcnew PointF((x + width), chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY->ValueToPixelPosition(fibonacci_levels[i]));

			g->DrawLine(fibPen, start->X, start->Y, end->X, end->Y);
		}
	}

	// If the rubberbanded wave is valid
	if (isValidWave(
		PVstart,
		chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisX->PixelPositionToValue(rectEnd.X),
		chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY->PixelPositionToValue(rectEnd.Y))
		)
	{
		//Then count the confirmations
		int conf = CountConfirmations(PVstart,
			chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisX->PixelPositionToValue(rectEnd.X),
			chart_LoadTicker->ChartAreas["ChartArea_OHLC"]->AxisY->PixelPositionToValue(rectEnd.Y),
			fibonacci_levels, e);

		// get the y value of the rectangle to display in string
		double y = chart_LoadTicker->ChartAreas[0]->AxisY->PixelPositionToValue(rectEnd.Y);
		//Update label displaying price and number of confirmations
		label_WaveIsValid->Text = "Wave: " + conf.ToString() + " confirmations @ $" + y.ToString("0.00");
	}
	else { label_WaveIsValid->Text = "Wave: Is Not Valid"; }
	}

/// <summary>
/// Given a high and a low calculate the fibonacci levels of the wave
/// </summary>
/// <param name="start"></param>
/// <param name="index"></param>
/// <param name="yPos"></param>
/// <returns></returns>
private: List<double>^ GetFibonacciLevels(PeakValley^ start, int index, double yPos) {
	
	List<double>^ fib = gcnew List<double>();
	double range;
	double high;
	if (start->IsPeak) {
		high = start->Cs->High;
		range = high - yPos;
	}
	else {
		high = yPos;
		range = yPos - start->Cs->Low;
	}

	//Populates array storing every fibonacci level as well as the size of the buffer
	fib->Add(high - range);
	fib->Add(high - (range * .764));
	fib->Add(high - (range * .618));
	fib->Add(high - (range * .5));
	fib->Add(high - (range * .382));
	fib->Add(high - (range * .236));
	fib->Add(high);
	fib->Add(range * 0.01);
	
	return fib;
}


/// <summary>
/// Given a set of fibonacci levels count the number of confirmations in the rectangle
/// </summary>
/// <param name="start"></param>
/// <param name="index"></param>
/// <param name="yPos"></param>
/// <param name="fib"></param>
/// <param name="e"></param>
/// <returns></returns>
private: int CountConfirmations(PeakValley^ start, int index, double yPos, List<double>^ fib, System::Windows::Forms::DataVisualization::Charting::ChartPaintEventArgs^ e) {
	double margin = fib[7];
	confirmations = 0;
	int dotRadius = 2;
	Graphics^ g = e->ChartGraphics->Graphics;
	for (int i = start->Index; i < index - 1; i++) {
		
		for (int j = 0; j < 7; j++) {
			//Check if Open Confirms
			if (filteredCandlesticks[i]->Open < fib[j] + margin && filteredCandlesticks[i]->Open > fib[j] - margin)
			{
				confirmations++; // increment the number of confirmations
				int centerX = (int)chart_LoadTicker->ChartAreas[0]->AxisX->ValueToPixelPosition((double)(i + 1)); // Find the x value of the dot
				double priceY = chart_LoadTicker->Series["Series_OHLC"]->Points[i]->YValues[2]; // find the y value of the dot
				priceY = chart_LoadTicker->ChartAreas[0]->AxisY->ValueToPixelPosition(priceY); // Get the actual pixel position of the y value
				g->FillEllipse(System::Drawing::Brushes::DeepPink, centerX - dotRadius, priceY - dotRadius, dotRadius * 2, dotRadius * 2); // Draw the dot
				
			}
			// Check if High Confirms
			if (filteredCandlesticks[i]->High < fib[j] + margin && filteredCandlesticks[i]->High > fib[j] - margin)
			{
				confirmations++;
				int centerX = (int)chart_LoadTicker->ChartAreas[0]->AxisX->ValueToPixelPosition((double)(i + 1));
				double priceY = chart_LoadTicker->Series["Series_OHLC"]->Points[i]->YValues[0];
				priceY = chart_LoadTicker->ChartAreas[0]->AxisY->ValueToPixelPosition(priceY);
				g->FillEllipse(System::Drawing::Brushes::DeepPink, centerX - dotRadius, priceY - dotRadius, dotRadius * 2, dotRadius * 2);
	
			}
			// Check if Low Confirms
			if (filteredCandlesticks[i]->Low < fib[j] + margin && filteredCandlesticks[i]->Low > fib[j] - margin)
			{
				confirmations++;
				int centerX = (int)chart_LoadTicker->ChartAreas[0]->AxisX->ValueToPixelPosition((double)(i + 1));
				double priceY = chart_LoadTicker->Series["Series_OHLC"]->Points[i]->YValues[1];
				priceY = chart_LoadTicker->ChartAreas[0]->AxisY->ValueToPixelPosition(priceY);
				g->FillEllipse(System::Drawing::Brushes::DeepPink, centerX - dotRadius, priceY - dotRadius, dotRadius * 2, dotRadius * 2);
			}

			// Check if Close Confirms
			if (filteredCandlesticks[i]->Close < fib[j] + margin && filteredCandlesticks[i]->Close > fib[j] - margin)
			{
				confirmations++;
				int centerX = (int)chart_LoadTicker->ChartAreas[0]->AxisX->ValueToPixelPosition((double)(i + 1));
				double priceY = chart_LoadTicker->Series["Series_OHLC"]->Points[i]->YValues[3];
				priceY = chart_LoadTicker->ChartAreas[0]->AxisY->ValueToPixelPosition(priceY);
				g->FillEllipse(System::Drawing::Brushes::DeepPink, centerX - dotRadius, priceY - dotRadius, dotRadius * 2, dotRadius * 2);
			}
		}
	}

	return confirmations;
}
	/// <summary>
	/// Function to remove all annotations with a specific tag
	/// </summary>
	/// <param name="s"></param>
	private: void RemoveAnnotaionsWithTag(String^ s) {
		// Create a list of indices to remove (if you remove in the middle of the for loop it can throw off the count and miss the last annotation)
		// so we store all the indices and remove them all at once
		List<int>^ indexesToRemove = gcnew List<int>();
		// Goes through all annotations and stores indexes of those associated with an upWave
		for (int i = 0; i < chart_LoadTicker->Annotations->Count; i++)
		{
			if (chart_LoadTicker->Annotations[i]->Tag == s) { indexesToRemove->Add(i); }
		}

		// Reverse the index array (now largest first so we dont go OOB)
		indexesToRemove->Reverse();

		// Remove Each index
		for each (int i in indexesToRemove)
		{
			chart_LoadTicker->Annotations->RemoveAt(i);
		}
	
	}

/// <summary>
/// Event handler for when the + range button is presses
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void button_IncUp_Click(System::Object^ sender, System::EventArgs^ e) {
	incUp(); // calls the incUp function
}

/// <summary>
/// Function that increases the range of the fibonacci rectangle
/// </summary>
private: void incUp() {
	stepCount++; // Increment the step count
	if (stepCount <= 20) { // if the step count is in range just add the stepsize to the end of the rectangle
		(rectStart_isPeak) ? rectEnd.Y -= range : rectEnd.Y += range;
	}
	else { 
		stepCount = -20; //wrap stepcount to the other side
		rectStart_isPeak ? rectEnd.Y = maxPrice : rectEnd.Y = minPrice; // set price accordingly
	}
	chart_LoadTicker->Invalidate(); // Redraw Chart
}

/// <summary>
/// Event handler for - range button
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void button_IncDown_Click(System::Object^ sender, System::EventArgs^ e) {
	//Same as incUp but in reverse
	stepCount--; // Decrement what step we are at
	if (stepCount >= -20) { // If that decrememt is in range
		(rectStart_isPeak) ? rectEnd.Y += range : rectEnd.Y -= range; // move the end of the rectangle accordingly
	}
	else {
		stepCount = 20; //wrap rectangle around to greatest range
		rectStart_isPeak ? rectEnd.Y = minPrice : rectEnd.Y = maxPrice; //wrap rectangle around to greatest range
	}
	chart_LoadTicker->Invalidate(); // redraw chart
}

/// <summary>
/// While the simulation is running just continually call incUp
/// </summary>
/// <param name="sender"></param>
/// <param name="e"></param>
/// <returns></returns>
private: System::Void timer_Simulation_Tick(System::Object^ sender, System::EventArgs^ e) {
	incUp();
	
}
private: System::Void button_Simulate_Click(System::Object^ sender, System::EventArgs^ e) {
	isSimulating = !isSimulating; // Lets button act as toggle
	
	// Sets all controls according to whether or not the simulation is running
	isSimulating ? button_Simulate->Text = "Stop Simulation" : button_Simulate->Text = "Start Simulation";
	isSimulating ? button_IncDown->Enabled = false : button_IncDown->Enabled = true;
	isSimulating ? button_IncUp->Enabled = false : button_IncUp->Enabled = true;
	isSimulating ? timer_Simulation->Start() : timer_Simulation->Stop();
}

/// <summary>
/// Shows the controls for the simulation
/// </summary>
private: void ShowSimulationControls() {
	this->button_IncDown->Visible = true;
	this->button_IncUp->Visible = true;
	this->label_Range->Visible = true;
	this->button_Simulate->Visible = true;
}
};
}
