
void asn1_add_error(uchar *address,int offset)

{
  char acStack_30 [16];
  char acStack_20 [20];
  
  BIO_snprintf(acStack_30,0xd,"%lu",address);
  BIO_snprintf(acStack_20,0xd,"%d",offset);
  ERR_add_error_data(4,"address=",acStack_30," offset=",acStack_20);
  return;
}

