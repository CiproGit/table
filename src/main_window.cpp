#include "main_window.h"
#include "./ui_main_window.h"

Main_window::Main_window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Main_window) {
	ui->setupUi(this);

	this->table = new QTableWidget(ui->table_frame);
	this->table->hide();

	ui->table_layout->addWidget(this->table);

	connect(ui->create_button, SIGNAL(clicked()), this, SLOT(on_create()));
}

Main_window::~Main_window() {
	delete this->table;
	delete ui;
}

void Main_window::on_create() {
	int rows = ui->rows_spinbox->value();
	int columns = ui->columns_spinbox->value();

	int rows_height = ui->rows_height_slider->value();
	int columns_width = ui->columns_width_slider->value();

	if (rows > 0 && columns > 0) {
		this->table->setRowCount(rows);
		this->table->setColumnCount(columns);

		for (unsigned int row_index = 0; row_index < rows; row_index++) {
			this->table->setRowHeight(row_index, rows_height);
		}

		for (unsigned int column_index = 0; column_index < columns; column_index++) {
			this->table->setColumnWidth(column_index, columns_width);
		}

		this->table->show();
	}
}
