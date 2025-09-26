
void dtls1_start_timer(SSL *param_1)

{
  undefined4 uVar1;
  BIO *bp;
  int iVar2;
  int iVar3;
  int iVar4;
  EVP_CIPHER_CTX *pEVar5;
  uint uVar6;
  
  pEVar5 = param_1->enc_read_ctx;
  if ((*(int *)pEVar5[2].final == 0) && (*(int *)(pEVar5[2].final + 4) == 0)) {
    if (*(code **)(pEVar5[2].final + 0x10) == (code *)0x0) {
      pEVar5[2].final[8] = '@';
      pEVar5[2].final[9] = 'B';
      pEVar5[2].final[10] = '\x0f';
      pEVar5[2].final[0xb] = '\0';
    }
    else {
      uVar1 = (**(code **)(pEVar5[2].final + 0x10))();
      *(undefined4 *)(pEVar5[2].final + 8) = uVar1;
      pEVar5 = param_1->enc_read_ctx;
    }
  }
  gettimeofday((timeval *)pEVar5[2].final,(__timezone_ptr_t)0x0);
  pEVar5 = param_1->enc_read_ctx;
  uVar6 = *(uint *)(pEVar5[2].final + 8) / 1000000;
  iVar3 = *(int *)(pEVar5[2].final + 4) + *(uint *)(pEVar5[2].final + 8) + uVar6 * -1000000;
  iVar2 = uVar6 + *(int *)pEVar5[2].final;
  *(int *)pEVar5[2].final = iVar2;
  *(int *)(pEVar5[2].final + 4) = iVar3;
  iVar4 = iVar3;
  if (999999 < iVar3) {
    iVar2 = iVar2 + 1;
    iVar4 = iVar3 + -1000000;
  }
  if (999999 < iVar3) {
    *(int *)pEVar5[2].final = iVar2;
  }
  if (999999 < iVar3) {
    *(int *)(pEVar5[2].final + 4) = iVar4;
  }
  bp = SSL_get_rbio(param_1);
  BIO_ctrl(bp,0x2d,0,param_1->enc_read_ctx[2].final);
  return;
}

