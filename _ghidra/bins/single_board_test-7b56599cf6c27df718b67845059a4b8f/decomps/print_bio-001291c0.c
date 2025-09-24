
void print_bio(void *param_1,int param_2,BIO *param_3)

{
  BIO_write(param_3,param_1,param_2);
  return;
}

