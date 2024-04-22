
X509 * ssl2_set_certificate(int param_1,undefined4 param_2,long param_3,uchar *param_4)

{
  X509 *x;
  _STACK *st;
  int iVar1;
  int iVar2;
  X509 *pXVar3;
  EVP_PKEY *pkey;
  uchar *local_1c;
  
  local_1c = param_4;
  x = d2i_X509((X509 **)0x0,&local_1c,param_3);
  if (x == (X509 *)0x0) {
    ERR_put_error(0x14,0x7e,0xb,DAT_00063c38,0x3f3);
    pXVar3 = (X509 *)0x0;
    pkey = (EVP_PKEY *)0x0;
    st = (_STACK *)0x0;
  }
  else {
    st = sk_new_null();
    if ((st == (_STACK *)0x0) || (iVar1 = sk_push(st,x), iVar1 == 0)) {
      pkey = (EVP_PKEY *)0x0;
      ERR_put_error(0x14,0x7e,0x41,DAT_00063c38,0x3f8);
      pXVar3 = (X509 *)0x0;
    }
    else {
      iVar1 = ssl_verify_cert_chain(param_1,st);
      if ((*(int *)(param_1 + 200) == 0) || (0 < iVar1)) {
        ERR_clear_error();
        *(undefined4 *)(*(int *)(param_1 + 0xc0) + 0xa0) = *(undefined4 *)(param_1 + 0xec);
        iVar1 = ssl_sess_cert_new();
        if (iVar1 == 0) {
          pXVar3 = (X509 *)0xffffffff;
          pkey = (EVP_PKEY *)0x0;
        }
        else {
          iVar2 = *(int *)(param_1 + 0xc0);
          if (*(int *)(iVar2 + 0x98) != 0) {
            ssl_sess_cert_free();
            iVar2 = *(int *)(param_1 + 0xc0);
          }
          *(int *)(iVar2 + 0x98) = iVar1;
          *(X509 **)(iVar1 + 0xc) = x;
          *(X509 ***)(iVar1 + 8) = (X509 **)(iVar1 + 0xc);
          pkey = X509_get_pubkey(x);
          if (pkey == (EVP_PKEY *)0x0) {
            ERR_put_error(0x14,0x7e,0xed,DAT_00063c38,0x416);
            x = (X509 *)0x0;
            pXVar3 = (X509 *)0x0;
          }
          else if (pkey->type == 6) {
            x = (X509 *)ssl_set_peer_cert_type(iVar1,1);
            pXVar3 = x;
            if (x != (X509 *)0x0) {
              pXVar3 = (X509 *)0x1;
              x = (X509 *)0x0;
            }
          }
          else {
            x = (X509 *)0x0;
            ERR_put_error(0x14,0x7e,0xd2,DAT_00063c38,0x41a);
            pXVar3 = x;
          }
        }
      }
      else {
        pXVar3 = (X509 *)0x0;
        ERR_put_error(0x14,0x7e,0x86,DAT_00063c38,0x3ff);
        pkey = (EVP_PKEY *)0x0;
      }
    }
  }
  sk_free(st);
  X509_free(x);
  EVP_PKEY_free(pkey);
  return pXVar3;
}

