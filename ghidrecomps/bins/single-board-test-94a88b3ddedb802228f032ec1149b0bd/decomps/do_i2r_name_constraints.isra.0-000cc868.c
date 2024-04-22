
undefined4
do_i2r_name_constraints_isra_0(_STACK *param_1,BIO *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  GENERAL_NAME **ppGVar3;
  GENERAL_NAME *gen;
  BUF_MEM *pBVar4;
  stack_st_X509_NAME_ENTRY *psVar5;
  
  iVar1 = sk_num(param_1);
  if (0 < iVar1) {
    BIO_printf(param_2,DAT_000ccab0,param_3,DAT_000ccab4,param_4);
  }
  for (iVar1 = 0; iVar2 = sk_num(param_1), iVar1 < iVar2; iVar1 = iVar1 + 1) {
    ppGVar3 = (GENERAL_NAME **)sk_value(param_1,iVar1);
    BIO_printf(param_2,DAT_000ccabc,param_3 + 2,DAT_000ccab4);
    gen = *ppGVar3;
    if (gen->type == 7) {
      psVar5 = ((gen->d).directoryName)->entries;
      pBVar4 = ((gen->d).directoryName)->bytes;
      BIO_puts(param_2,DAT_000ccac0);
      if (psVar5 == (stack_st_X509_NAME_ENTRY *)0x8) {
        BIO_printf(param_2,DAT_000ccad4,(uint)*(byte *)&pBVar4->length,
                   (uint)*(byte *)((int)&pBVar4->length + 1),
                   (uint)*(byte *)((int)&pBVar4->length + 2),
                   (uint)*(byte *)((int)&pBVar4->length + 3),(uint)*(byte *)&pBVar4->data,
                   (uint)*(byte *)((int)&pBVar4->data + 1),(uint)*(byte *)((int)&pBVar4->data + 2),
                   (uint)*(byte *)((int)&pBVar4->data + 3));
      }
      else if (psVar5 == (stack_st_X509_NAME_ENTRY *)0x20) {
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)&pBVar4->length,
                                  *(undefined *)((int)&pBVar4->length + 1)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4->length + 2),
                                  *(undefined *)((int)&pBVar4->length + 3)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)&pBVar4->data,*(undefined *)((int)&pBVar4->data + 1)
                                 ));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4->data + 2),
                                  *(undefined *)((int)&pBVar4->data + 3)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)&pBVar4->max,*(undefined *)((int)&pBVar4->max + 1)))
        ;
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4->max + 2),
                                  *(undefined *)((int)&pBVar4->max + 3)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)&pBVar4[1].length,
                                  *(undefined *)((int)&pBVar4[1].length + 1)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4[1].length + 2),
                                  *(undefined *)((int)&pBVar4[1].length + 3)));
        BIO_puts(param_2,DAT_000ccacc);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)&pBVar4[1].data,
                                  *(undefined *)((int)&pBVar4[1].data + 1)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4[1].data + 2),
                                  *(undefined *)((int)&pBVar4[1].data + 3)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)&pBVar4[1].max,
                                  *(undefined *)((int)&pBVar4[1].max + 1)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4[1].max + 2),
                                  *(undefined *)((int)&pBVar4[1].max + 3)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)&pBVar4[2].length,
                                  *(undefined *)((int)&pBVar4[2].length + 1)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4[2].length + 2),
                                  *(undefined *)((int)&pBVar4[2].length + 3)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)&pBVar4[2].data,
                                  *(undefined *)((int)&pBVar4[2].data + 1)));
        BIO_puts(param_2,DAT_000ccac8);
        BIO_printf(param_2,DAT_000ccac4,
                   (uint)CONCAT11(*(undefined *)((int)&pBVar4[2].data + 2),
                                  *(undefined *)((int)&pBVar4[2].data + 3)));
      }
      else {
        BIO_printf(param_2,DAT_000ccad0);
      }
    }
    else {
      GENERAL_NAME_print(param_2,gen);
    }
    BIO_puts(param_2,DAT_000ccab8);
  }
  return 1;
}

