
/* WARNING: Unknown calling convention */

api_data * api_add_escape(api_data *root,char *name,char *data,_Bool copy_data)

{
  api_data *paVar1;
  
  paVar1 = api_add_data_full(root,name,API_ESCAPE,data,copy_data);
  return paVar1;
}

