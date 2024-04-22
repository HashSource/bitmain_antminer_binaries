
void print_fp(undefined4 param_1,undefined4 param_2,void *param_3)

{
  BIO_METHOD *type;
  BIO BStack_50;
  
  type = BIO_s_file();
  BIO_set(&BStack_50,type);
  BIO_ctrl(&BStack_50,0x6a,0,param_3);
  BIO_printf(&BStack_50,"%s",param_1);
  return;
}

