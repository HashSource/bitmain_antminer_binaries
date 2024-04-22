
int GENERAL_NAME_print(BIO *out,GENERAL_NAME *gen)

{
  stack_st_X509_NAME_ENTRY *psVar1;
  BUF_MEM *pBVar2;
  
  switch(gen->type) {
  case 0:
    BIO_printf(out,DAT_000c8d70);
    break;
  case 1:
    BIO_printf(out,DAT_000c8d74,((gen->d).rfc822Name)->data);
    break;
  case 2:
    BIO_printf(out,DAT_000c8d78,((gen->d).rfc822Name)->data);
    break;
  case 3:
    BIO_printf(out,DAT_000c8d7c);
    break;
  case 4:
    BIO_printf(out,DAT_000c8d80);
    X509_NAME_print_ex(out,(gen->d).directoryName,0,0x82031f);
    break;
  case 5:
    BIO_printf(out,DAT_000c8d84);
    break;
  case 6:
    BIO_printf(out,DAT_000c8d88,((gen->d).rfc822Name)->data);
    break;
  case 7:
    psVar1 = ((gen->d).directoryName)->entries;
    pBVar2 = ((gen->d).directoryName)->bytes;
    if (psVar1 == (stack_st_X509_NAME_ENTRY *)0x4) {
      BIO_printf(out,DAT_000c8d98,(uint)*(byte *)&pBVar2->length,
                 (uint)*(byte *)((int)&pBVar2->length + 1),(uint)*(byte *)((int)&pBVar2->length + 2)
                 ,(uint)*(byte *)((int)&pBVar2->length + 3));
    }
    else if (psVar1 == (stack_st_X509_NAME_ENTRY *)0x10) {
      BIO_printf(out,DAT_000c8d8c);
      BIO_printf(out,DAT_000c8d90,
                 (uint)CONCAT11(*(undefined *)&pBVar2->length,
                                *(undefined *)((int)&pBVar2->length + 1)));
      BIO_printf(out,DAT_000c8d90,
                 (uint)CONCAT11(*(undefined *)((int)&pBVar2->length + 2),
                                *(undefined *)((int)&pBVar2->length + 3)));
      BIO_printf(out,DAT_000c8d90,
                 (uint)CONCAT11(*(undefined *)&pBVar2->data,*(undefined *)((int)&pBVar2->data + 1)))
      ;
      BIO_printf(out,DAT_000c8d90,
                 (uint)CONCAT11(*(undefined *)((int)&pBVar2->data + 2),
                                *(undefined *)((int)&pBVar2->data + 3)));
      BIO_printf(out,DAT_000c8d90,
                 (uint)CONCAT11(*(undefined *)&pBVar2->max,*(undefined *)((int)&pBVar2->max + 1)));
      BIO_printf(out,DAT_000c8d90,
                 (uint)CONCAT11(*(undefined *)((int)&pBVar2->max + 2),
                                *(undefined *)((int)&pBVar2->max + 3)));
      BIO_printf(out,DAT_000c8d90,
                 (uint)CONCAT11(*(undefined *)&pBVar2[1].length,
                                *(undefined *)((int)&pBVar2[1].length + 1)));
      BIO_printf(out,DAT_000c8d90,
                 (uint)CONCAT11(*(undefined *)((int)&pBVar2[1].length + 2),
                                *(undefined *)((int)&pBVar2[1].length + 3)));
      BIO_puts(out,DAT_000c8d94);
    }
    else {
      BIO_printf(out,DAT_000c8d68);
    }
    break;
  case 8:
    BIO_printf(out,DAT_000c8d6c);
    i2a_ASN1_OBJECT(out,(gen->d).registeredID);
  }
  return 1;
}

