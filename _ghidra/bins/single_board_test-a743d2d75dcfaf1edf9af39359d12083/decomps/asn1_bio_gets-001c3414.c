
void asn1_bio_gets(int param_1,char *param_2,int param_3)

{
  if (*(BIO **)(param_1 + 0x24) != (BIO *)0x0) {
    BIO_gets(*(BIO **)(param_1 + 0x24),param_2,param_3);
    return;
  }
  return;
}

