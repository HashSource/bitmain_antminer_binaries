
undefined4
do_i2r_name_constraints_isra_4(undefined4 param_1,BIO *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  GENERAL_NAME *gen;
  BUF_MEM *pBVar4;
  stack_st_X509_NAME_ENTRY *psVar5;
  int iVar6;
  
  iVar1 = OPENSSL_sk_num();
  if (0 < iVar1) {
    BIO_printf(param_2,"%*s%s:\n",param_3,"",param_4);
  }
  iVar1 = 0;
  do {
    iVar2 = OPENSSL_sk_num(param_1);
    if (iVar2 <= iVar1) {
      return 1;
    }
    puVar3 = (undefined4 *)OPENSSL_sk_value(param_1,iVar1);
    BIO_printf(param_2,"%*s",param_3 + 2,"");
    gen = (GENERAL_NAME *)*puVar3;
    if (gen->type == 7) {
      psVar5 = ((gen->d).directoryName)->entries;
      pBVar4 = ((gen->d).directoryName)->bytes;
      BIO_puts(param_2,"IP:");
      if (psVar5 == (stack_st_X509_NAME_ENTRY *)0x8) {
        BIO_printf(param_2,"%d.%d.%d.%d/%d.%d.%d.%d",(uint)(byte)pBVar4->length,
                   (uint)*(byte *)((int)&pBVar4->length + 1),
                   (uint)*(byte *)((int)&pBVar4->length + 2),
                   (uint)*(byte *)((int)&pBVar4->length + 3),(uint)*(byte *)&pBVar4->data,
                   (uint)*(byte *)((int)&pBVar4->data + 1),(uint)*(byte *)((int)&pBVar4->data + 2),
                   (uint)*(byte *)((int)&pBVar4->data + 3));
      }
      else {
        if (psVar5 == (stack_st_X509_NAME_ENTRY *)0x20) {
          iVar6 = 1;
          iVar2 = 0;
          do {
            BIO_printf(param_2,"%X",
                       (uint)CONCAT11((char)pBVar4->length,*(undefined1 *)((int)&pBVar4->length + 1)
                                     ));
            if (iVar2 == 7) {
              BIO_puts(param_2,"/");
            }
            else if ((iVar2 == 0xf) || (BIO_puts(param_2,":"), iVar6 == 0x10)) goto LAB_00171eae;
            iVar2 = iVar2 + 1;
            iVar6 = iVar6 + 1;
            pBVar4 = (BUF_MEM *)((int)&pBVar4->length + 2);
          } while( true );
        }
        BIO_printf(param_2,"IP Address:<invalid>");
      }
    }
    else {
      GENERAL_NAME_print(param_2,gen);
    }
LAB_00171eae:
    iVar1 = iVar1 + 1;
    BIO_puts(param_2,"\n");
  } while( true );
}

