
void PEM_write_DHxparams(FILE *param_1,void *param_2)

{
  PEM_ASN1_write(i2d_DHxparams + 1,"X9.42 DH PARAMETERS",param_1,param_2,(EVP_CIPHER *)0x0,
                 (uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
  return;
}

