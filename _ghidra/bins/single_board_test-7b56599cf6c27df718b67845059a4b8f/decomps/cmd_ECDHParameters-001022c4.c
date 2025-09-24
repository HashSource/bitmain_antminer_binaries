
bool cmd_ECDHParameters(int *param_1,char *param_2)

{
  int iVar1;
  EC_KEY *key;
  long lVar2;
  bool bVar3;
  int iVar4;
  
  iVar4 = *param_1;
  if (((-1 < iVar4 << 0x1e) ||
      ((iVar1 = strcasecmp(param_2,"+automatic"), iVar1 != 0 &&
       (iVar1 = strcasecmp(param_2,"automatic"), iVar1 != 0)))) &&
     ((-1 < iVar4 << 0x1f || (iVar4 = strcmp(param_2,"auto"), iVar4 != 0)))) {
    iVar4 = EC_curve_nist2nid(param_2);
    if (((iVar4 != 0) || (iVar4 = OBJ_sn2nid(param_2), iVar4 != 0)) &&
       (key = EC_KEY_new_by_curve_name(iVar4), key != (EC_KEY *)0x0)) {
      if ((SSL_CTX *)param_1[3] == (SSL_CTX *)0x0) {
        if ((SSL *)param_1[4] == (SSL *)0x0) {
          bVar3 = true;
        }
        else {
          lVar2 = SSL_ctrl((SSL *)param_1[4],4,0,key);
          bVar3 = 0 < lVar2;
        }
      }
      else {
        lVar2 = SSL_CTX_ctrl((SSL_CTX *)param_1[3],4,0,key);
        if (lVar2 < 1) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
      }
      EC_KEY_free(key);
      return bVar3;
    }
    return false;
  }
  return true;
}

