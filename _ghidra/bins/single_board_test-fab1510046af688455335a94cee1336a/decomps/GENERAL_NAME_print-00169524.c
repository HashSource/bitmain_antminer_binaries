
int GENERAL_NAME_print(BIO *out,GENERAL_NAME *gen)

{
  stack_st_X509_NAME_ENTRY *psVar1;
  BUF_MEM *pBVar2;
  
  switch(gen->type) {
  case 0:
    BIO_printf(out,"othername:<unsupported>");
    break;
  case 1:
    BIO_printf(out,"email:%s",((gen->d).rfc822Name)->data);
    break;
  case 2:
    BIO_printf(out,"DNS:%s",((gen->d).rfc822Name)->data);
    break;
  case 3:
    BIO_printf(out,"X400Name:<unsupported>");
    break;
  case 4:
    BIO_printf(out,"DirName: ");
    X509_NAME_print_ex(out,(gen->d).directoryName,0,0x82031f);
    break;
  case 5:
    BIO_printf(out,"EdiPartyName:<unsupported>");
    break;
  case 6:
    BIO_printf(out,"URI:%s",((gen->d).rfc822Name)->data);
    break;
  case 7:
    psVar1 = ((gen->d).directoryName)->entries;
    pBVar2 = ((gen->d).directoryName)->bytes;
    if (psVar1 == (stack_st_X509_NAME_ENTRY *)0x4) {
      BIO_printf(out,"IP Address:%d.%d.%d.%d",(uint)(byte)pBVar2->length,
                 (uint)*(byte *)((int)&pBVar2->length + 1),(uint)*(byte *)((int)&pBVar2->length + 2)
                 ,(uint)*(byte *)((int)&pBVar2->length + 3));
    }
    else if (psVar1 == (stack_st_X509_NAME_ENTRY *)0x10) {
      BIO_printf(out,"IP Address");
      BIO_printf(out,":%X",
                 (uint)CONCAT11((char)pBVar2->length,*(undefined1 *)((int)&pBVar2->length + 1)));
      BIO_printf(out,":%X",
                 (uint)CONCAT11(*(undefined1 *)((int)&pBVar2->length + 2),
                                *(undefined1 *)((int)&pBVar2->length + 3)));
      BIO_printf(out,":%X",
                 (uint)CONCAT11(*(undefined1 *)&pBVar2->data,*(undefined1 *)((int)&pBVar2->data + 1)
                               ));
      BIO_printf(out,":%X",
                 (uint)CONCAT11(*(undefined1 *)((int)&pBVar2->data + 2),
                                *(undefined1 *)((int)&pBVar2->data + 3)));
      BIO_printf(out,":%X",(uint)CONCAT11((char)pBVar2->max,*(undefined1 *)((int)&pBVar2->max + 1)))
      ;
      BIO_printf(out,":%X",
                 (uint)CONCAT11(*(undefined1 *)((int)&pBVar2->max + 2),
                                *(undefined1 *)((int)&pBVar2->max + 3)));
      BIO_printf(out,":%X",
                 (uint)CONCAT11((char)pBVar2[1].length,*(undefined1 *)((int)&pBVar2[1].length + 1)))
      ;
      BIO_printf(out,":%X",
                 (uint)CONCAT11(*(undefined1 *)((int)&pBVar2[1].length + 2),
                                *(undefined1 *)((int)&pBVar2[1].length + 3)));
      BIO_puts(out,"\n");
    }
    else {
      BIO_printf(out,"IP Address:<invalid>");
    }
    break;
  case 8:
    BIO_printf(out,"Registered ID");
    i2a_ASN1_OBJECT(out,(gen->d).registeredID);
  }
  return 1;
}

