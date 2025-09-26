
int config_get_tpl_data(int row,int column)

{
  int column_local;
  int row_local;
  
  return (Local_Config_Information->tpl).data[column + row * (Local_Config_Information->tpl).column]
  ;
}

