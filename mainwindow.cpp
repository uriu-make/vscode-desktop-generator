#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  setFixedSize(width(), height());
  connect(ui->Directory, SIGNAL(clicked()), this, SLOT(open_file_dialog()));
  connect(ui->actionQuit, SIGNAL(triggered()), this, SLOT(close()));
  // connect(ui->Generate_name, SIGNAL(editingFinished()), this, SLOT(toggle_generate_button()));
  connect(ui->Generate, SIGNAL(clicked()), this, SLOT(generate()));
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::open_file_dialog() {
  QString filters("code-workspace files (*.code-workspace);;All files(*.*)");
  QString defaultFilter("code-workspace files (*.code-workspace)");
  QString rootpath(QStandardPaths::writableLocation(QStandardPaths::HomeLocation));
  QFileDialog file_dialog;
  file_dialog.setFileMode(QFileDialog::Directory);
  file_dialog.setOption(QFileDialog::ShowDirsOnly, true);
  QString dirName = file_dialog.getOpenFileName(0, "ファイルを選択してください。", rootpath, filters, &defaultFilter, QFileDialog::ShowDirsOnly);
  if (!dirName.isEmpty()) {
    ui->workspace_file_path->setText(dirName);
  }
  return;
}

void MainWindow::toggle_generate_button() {
  if (ui->workspace_file_path->text().length() > 0 &&
      ui->Generate_name->text().length() > 0) {
    ui->Generate->setEnabled(true);
  } else {
    ui->Generate->setEnabled(false);
  }
  return;
}

void MainWindow::generate() {
  QString desktop_filepath(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + '/' + ui->Generate_name->text() + ".desktop");
  QFile desktop_file(desktop_filepath);
  if (ui->workspace_file_path->text().length() <= 0 &&
      ui->Generate_name->text().length() <= 0) {
    return;
  }
  if (QFile::exists(desktop_filepath)) {
    QMessageBox warning;
    enum QMessageBox::StandardButton button = warning.information(this, "Warnings", "File is already exists.\nOverwrite?", QMessageBox::Ok, QMessageBox::Cancel);
    if (button == QMessageBox::Cancel) {
      return;
    }
  }

  if (desktop_file.open(QIODevice::WriteOnly)) {
    QTextStream output(&desktop_file);

    output << "[Desktop Entry]" << Qt::endl;
    output << "Name=" << ui->Generate_name->text() << Qt::endl;
    output << "Comment=Code Editing. Redefined." << Qt::endl;
    output << "GenericName=Text Editor" << Qt::endl;
    output << "Exec=/usr/share/code/code --unity-launch " << ui->workspace_file_path->text() << Qt::endl;
    output << "Icon=vscode" << Qt::endl;
    output << "Type=Application" << Qt::endl;
    output << "StartupNotify=false" << Qt::endl;
    output << "StartupWMClass=Code" << Qt::endl;
    output << "Categories=TextEditor;Development;IDE;" << Qt::endl;
    output << "MimeType=text/plain;inode/directory;application/x-code-workspace;" << Qt::endl;
    output << "Actions=new-empty-window;" << Qt::endl;
    output << "Keywords=vscode;" << Qt::endl;
    output << Qt::endl;
    output << "[Desktop Action new-empty-window]" << Qt::endl;
    output << "Name=New Empty Window" << Qt::endl;
    output << "Exec=/usr/share/code/code --new-window " << ui->workspace_file_path->text() << Qt::endl;
    output << "Icon=com.visualstudio.code" << Qt::endl;
    desktop_file.close();
  } else {
    // qWarning().noquote() << "Cannot open file" << desktop_filepath << Qt::endl;
  }
  this->close();
  return;
}