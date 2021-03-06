#include "model_attr_init_value.h"
#include "ui_model_attr_init_value.h"

ModelAttrInitValue::ModelAttrInitValue(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::ModelAttrInitValue)
{
  ui->setupUi(this);

  // Connect Signals and Slots
  connect(ui->check_value, SIGNAL(toggled(bool)), this, SLOT(EmitValueChanged()));
  connect(ui->sb_value,    SIGNAL(valueChanged(int)), this, SLOT(EmitValueChanged()));
  connect(ui->dsb_value,   SIGNAL(valueChanged(double)), this, SLOT(EmitValueChanged()));
  connect(ui->cb_value,    SIGNAL(currentIndexChanged(int)), this, SLOT(EmitValueChanged()));
}

ModelAttrInitValue::~ModelAttrInitValue()
{
  delete ui;
}

void ModelAttrInitValue::SetAttrName(std::string new_name) {
  ui->lbl_name->setText(QString::fromStdString(new_name));
}

void ModelAttrInitValue::SetWidgetDetails(Attribute* corresponding_attribute) {
  std::string attr_type = corresponding_attribute->m_type;

  if (attr_type == "Bool")
    ui->stk_type_pages->setCurrentWidget(ui->page_bool);

  else if (attr_type == "Integer")
    ui->stk_type_pages->setCurrentWidget(ui->page_integer);

  else if (attr_type == "Float")
    ui->stk_type_pages->setCurrentWidget(ui->page_float);

  else if (attr_type == "List") {
    std::string list_type = corresponding_attribute->m_list_type;

    if (list_type == "Bool")
      ui->stk_type_pages->setCurrentWidget(ui->page_bool);

    else if (list_type == "Integer")
      ui->stk_type_pages->setCurrentWidget(ui->page_integer);

    else if (list_type == "Float")
      ui->stk_type_pages->setCurrentWidget(ui->page_float);

    else if (list_type == "User Defined")
      ui->stk_type_pages->setCurrentWidget(ui->page_user_defined);

      // Add allowed values
      ui->cb_value->clear();
      if(corresponding_attribute->m_user_defined_values != nullptr)
        for (int i=0; i < corresponding_attribute->m_user_defined_values->size(); ++i)
          ui->cb_value->addItem(QString::fromStdString((*corresponding_attribute->m_user_defined_values)[i]));
      ui->cb_value->setCurrentIndex(0);

  } else if (attr_type == "User Defined") {
    ui->stk_type_pages->setCurrentWidget(ui->page_user_defined);

    // Add allowed values
    ui->cb_value->clear();
    if(corresponding_attribute->m_user_defined_values != nullptr)
      for (int i=0; i < corresponding_attribute->m_user_defined_values->size(); ++i)
        ui->cb_value->addItem(QString::fromStdString((*corresponding_attribute->m_user_defined_values)[i]));
    ui->cb_value->setCurrentIndex(0);
  }

  m_curr_page = ui->stk_type_pages->currentWidget();
  EmitValueChanged();
}

std::string ModelAttrInitValue::GetAttrName()
{
   return ui->lbl_name->text().toStdString();
}

std::string ModelAttrInitValue::GetInitValue() {
  if(ui->stk_type_pages->currentWidget() == ui->page_bool)
    return std::to_string(ui->check_value->isChecked());

  else if(ui->stk_type_pages->currentWidget() == ui->page_integer)
    return std::to_string(ui->sb_value->value());

  else if(ui->stk_type_pages->currentWidget() == ui->page_float)
    return std::to_string((float) ui->dsb_value->value());

  else if(ui->stk_type_pages->currentWidget() == ui->page_user_defined)
    return ui->cb_value->currentText().toStdString();
  else
    return "GetInitValue is wrong";
}

void ModelAttrInitValue::EmitValueChanged() {
  emit InitValueChanged(ui->lbl_name->text().toStdString(), GetInitValue());
}
