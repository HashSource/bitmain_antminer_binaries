
/* WARNING: Unknown calling convention */

api_data * api_add_uint16(api_data *root,char *name,uint16_t *data,_Bool copy_data)

{
  api_data *paVar1;
  
  paVar1 = api_add_data_full(root,name,API_UINT16,data,copy_data);
  return paVar1;
}

