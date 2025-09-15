
/* WARNING: Unknown calling convention */

api_data * api_add_percent(api_data *root,char *name,double *data,_Bool copy_data)

{
  api_data *paVar1;
  
  paVar1 = api_add_data_full(root,name,API_PERCENT,data,copy_data);
  return paVar1;
}

