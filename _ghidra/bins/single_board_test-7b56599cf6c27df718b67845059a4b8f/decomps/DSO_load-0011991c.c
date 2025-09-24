
DSO * DSO_load(DSO *dso,char *filename,DSO_METHOD *meth,int flags)

{
  bool bVar1;
  int iVar2;
  stack_st_void *psVar3;
  char *pcVar4;
  long lVar5;
  char *extraout_r2;
  _func_3874 *p_Var6;
  DSO_MERGER_FUNC pDVar7;
  undefined8 uVar8;
  
  bVar1 = false;
  if (dso == (DSO *)0x0) {
    if (default_DSO_meth == (DSO_METHOD *)0x0) {
      default_DSO_meth = DSO_METHOD_openssl();
    }
    dso = (DSO *)CRYPTO_zalloc(0x28,"crypto/dso/dso_lib.c",0x1b);
    if (dso == (DSO *)0x0) {
      ERR_put_error(0x25,0x71,0x41,"crypto/dso/dso_lib.c",0x1d);
    }
    else {
      psVar3 = (stack_st_void *)OPENSSL_sk_new_null();
      dso->meth_data = psVar3;
      if (psVar3 == (stack_st_void *)0x0) {
        ERR_put_error(0x25,0x71,0x41,"crypto/dso/dso_lib.c",0x23);
        CRYPTO_free(dso);
      }
      else {
        dso->meth = default_DSO_meth;
        DataMemoryBarrier(0x1b);
        dso->references = 1;
        DataMemoryBarrier(0x1b);
        uVar8 = CRYPTO_THREAD_lock_new();
        dso->loaded_filename = (char *)uVar8;
        if ((char *)uVar8 == (char *)0x0) {
          ERR_put_error(0x25,0x71,0x41,"crypto/dso/dso_lib.c",0x2b);
          OPENSSL_sk_free(dso->meth_data);
          CRYPTO_free(dso);
        }
        else {
          pDVar7 = dso->meth->dso_merger;
          if ((pDVar7 == (DSO_MERGER_FUNC)0x0) ||
             (pcVar4 = (*pDVar7)(dso,(char *)((ulonglong)uVar8 >> 0x20),extraout_r2),
             pcVar4 != (char *)0x0)) {
            lVar5 = DSO_ctrl(dso,2,flags,(void *)0x0);
            if (-1 < lVar5) {
              bVar1 = true;
              goto LAB_00119928;
            }
            ERR_put_error(0x25,0x70,100,"crypto/dso/dso_lib.c",0x85);
            goto LAB_001199ee;
          }
          DSO_free(dso);
        }
      }
    }
    ERR_put_error(0x25,0x70,0x41,"crypto/dso/dso_lib.c",0x7f);
  }
  else {
LAB_00119928:
    if (dso->merger == (DSO_MERGER_FUNC)0x0) {
      if (filename == (char *)0x0) {
LAB_00119a0a:
        ERR_put_error(0x25,0x70,0x6f,"crypto/dso/dso_lib.c",0x9a);
      }
      else {
        iVar2 = DSO_set_filename(dso,filename);
        if (iVar2 == 0) {
          ERR_put_error(0x25,0x70,0x70,"crypto/dso/dso_lib.c",0x95);
        }
        else {
          if (dso->merger == (DSO_MERGER_FUNC)0x0) goto LAB_00119a0a;
          p_Var6 = dso->meth->dso_load;
          if (p_Var6 == (_func_3874 *)0x0) {
            ERR_put_error(0x25,0x70,0x6c,"crypto/dso/dso_lib.c",0x9e);
          }
          else {
            iVar2 = (*p_Var6)(dso);
            if (iVar2 != 0) {
              return dso;
            }
            ERR_put_error(0x25,0x70,0x67,"crypto/dso/dso_lib.c",0xa2);
          }
        }
      }
    }
    else {
      ERR_put_error(0x25,0x70,0x6e,"crypto/dso/dso_lib.c",0x8c);
    }
    if (!bVar1) {
      return (DSO *)0x0;
    }
LAB_001199ee:
    DSO_free(dso);
  }
  return (DSO *)0x0;
}

