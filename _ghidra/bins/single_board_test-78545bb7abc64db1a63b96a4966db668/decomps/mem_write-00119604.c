
size_t mem_write(BIO *param_1,void *param_2,size_t param_3)

{
  int iVar1;
  char *pcVar2;
  char *__src;
  _func_737 *p_Var3;
  BIO_METHOD *pBVar4;
  _func_738 *p_Var5;
  _func_745 *p_Var6;
  bio_st *pbVar7;
  size_t sVar8;
  bio_st *pbVar9;
  int iVar10;
  
  pbVar9 = param_1->next_bio;
  if (param_2 == (void *)0x0) {
    sVar8 = 0xffffffff;
    ERR_put_error(0x20,0x75,0x73,"crypto/bio/bss_mem.c",0xe0);
  }
  else if ((param_1->retry_reason & 0x200U) == 0) {
    BIO_clear_flags(param_1,0xf);
    sVar8 = 0;
    if (param_3 != 0) {
      iVar10 = *(int *)pbVar9->callback;
      if ((param_1->shutdown != 0) && (pbVar7 = param_1->next_bio, pbVar7 != (bio_st *)0x0)) {
        __src = *(char **)(pbVar7->callback + 4);
        pcVar2 = pbVar7->method->name;
        if (__src != pcVar2) {
          memmove(pcVar2,__src,*(size_t *)pbVar7->callback);
          pBVar4 = pbVar7->method;
          p_Var6 = pbVar7->callback;
          pBVar4->type = *(int *)p_Var6;
          *(char **)(p_Var6 + 4) = pBVar4->name;
        }
      }
      iVar1 = BUF_MEM_grow_clean((BUF_MEM *)pbVar9->method,param_3 + iVar10);
      if (iVar1 == 0) {
        sVar8 = 0xffffffff;
      }
      else {
        memcpy(pbVar9->method->name + iVar10,param_2,param_3);
        pBVar4 = pbVar9->method;
        p_Var6 = pbVar9->callback;
        pcVar2 = pBVar4->name;
        p_Var3 = pBVar4->bwrite;
        p_Var5 = pBVar4->bread;
        *(int *)p_Var6 = pBVar4->type;
        *(char **)(p_Var6 + 4) = pcVar2;
        *(_func_737 **)(p_Var6 + 8) = p_Var3;
        *(_func_738 **)(p_Var6 + 0xc) = p_Var5;
        sVar8 = param_3;
      }
    }
  }
  else {
    sVar8 = 0xffffffff;
    ERR_put_error(0x20,0x75,0x7e,"crypto/bio/bss_mem.c",0xe4);
  }
  return sVar8;
}

