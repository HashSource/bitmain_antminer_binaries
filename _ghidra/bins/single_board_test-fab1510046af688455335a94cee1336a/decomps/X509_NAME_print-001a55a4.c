
int X509_NAME_print(BIO *bp,X509_NAME *name,int obase)

{
  char *pcVar1;
  char *ptr;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char *data;
  
  ptr = X509_NAME_oneline(name,(char *)0x0,0);
  if (ptr == (char *)0x0) {
    iVar2 = 0;
  }
  else if (*ptr == '\0') {
    CRYPTO_free(ptr);
    iVar2 = 1;
  }
  else {
    pcVar4 = ptr + 1;
    pcVar1 = ptr;
    data = ptr + 1;
LAB_001a55c8:
    do {
      pcVar5 = pcVar1;
      pcVar3 = pcVar4;
      pcVar1 = pcVar5 + 1;
      pcVar4 = pcVar3 + 1;
      if (*pcVar1 == '/') {
        if ((0x19 < (byte)pcVar5[2] - 0x41) ||
           (((byte)pcVar5[3] != 0x3d && ((0x19 < (byte)pcVar5[3] - 0x41 || (pcVar5[4] != '='))))))
        goto LAB_001a55c8;
      }
      else if (*pcVar1 != '\0') goto LAB_001a55c8;
      iVar2 = BIO_write(bp,data,(int)pcVar1 - (int)data);
      if (iVar2 != (int)pcVar1 - (int)data) {
LAB_001a5632:
        iVar2 = 0;
        ERR_put_error(0xb,0x75,7,"t_x509.c",0x227);
        goto LAB_001a55f0;
      }
      if (*pcVar3 == '\0') break;
      iVar2 = BIO_write(bp,&DAT_00218880,2);
      if (iVar2 != 2) goto LAB_001a5632;
      data = pcVar4;
    } while (*pcVar3 != '\0');
    iVar2 = 1;
LAB_001a55f0:
    CRYPTO_free(ptr);
  }
  return iVar2;
}

