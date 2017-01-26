#ifndef CA_MODELER_MANAGER_H
#define CA_MODELER_MANAGER_H

#include "../ca_model/ca_model.h"
#include "../ca_model/attribute.h"
#include <vector>
#include <string>

#include "QListWidgetItem"
#include "QHash"

class CAModelerManager
{

public:
  CAModelerManager();

  // Attributes
  attribute_type AttrTypeFromStr(std::string string_type);
  void AddCellAttribute(QListWidgetItem* corresponding_item);
  void RemoveCellAttribute(QListWidgetItem* target_item);
  void ModifyCellAttribute(QListWidgetItem* target_item,
                      const std::string &name, const std::string &type, const std::string &description,
                      int list_length, const std::string &list_type,
                      const QListWidget *user_defined_values);
  Attribute* GetCellAttribute(QListWidgetItem* target_item) {
    return m_cell_attributes.value(target_item);
  }

private:
  CAModel *m_ca_model;

  QHash<QListWidgetItem*, Attribute*>    m_cell_attributes;
  QHash<QListWidgetItem*, Attribute*>    m_model_attributes;
  QHash<QListWidgetItem*, Neighborhood*> m_neighborhoods;
  QHash<QListWidgetItem*, Partition*>    m_partitions;
  QHash<QListWidgetItem*, GraphNode*>    m_update_rules;
  QHash<QListWidgetItem*, GraphNode*>    m_mappings;
};

#endif // CA_MODELER_MANAGER_H
