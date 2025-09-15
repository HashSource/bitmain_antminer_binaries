
/* WARNING: Unknown calling convention */

api_data * api_add_uint8(api_data *root,char *name,uchar *data,_Bool copy_data)

{
  api_data *paVar1;
  
  paVar1 = api_add_data_full(root,name,API_UINT8,data,copy_data);
  return paVar1;
}

