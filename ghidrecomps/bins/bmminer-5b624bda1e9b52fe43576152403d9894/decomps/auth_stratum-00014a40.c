
/* WARNING: Unknown calling convention */

_Bool auth_stratum(pool *pool)

{
  int *piVar1;
  int *piVar2;
  undefined *puVar3;
  _Bool _Var4;
  size_t sVar5;
  char *pcVar6;
  json_t *json;
  json_t *pjVar7;
  json_t *res_val;
  json_t *json_00;
  json_t *err_val;
  undefined4 *puVar8;
  char *__retval;
  undefined4 uVar9;
  int iVar10;
  undefined4 uVar11;
  char *pcVar12;
  size_t sVar13;
  undefined4 uVar14;
  char *pcVar15;
  char *ss;
  undefined4 uVar16;
  json_error_t err;
  char tmp42 [2048];
  char s [8192];
  
  pcVar6 = DAT_00014c0c;
  piVar1 = DAT_00014c08;
  pcVar15 = pool->rpc_pass;
  iVar10 = *DAT_00014c08;
  pcVar12 = pool->rpc_user;
  *DAT_00014c08 = iVar10 + 1;
  sprintf(s,pcVar6,iVar10,pcVar12,pcVar15);
  sVar5 = strlen(s);
  _Var4 = stratum_send(pool,s,sVar5);
  if (_Var4) {
    while (pcVar6 = recv_line(pool), pcVar6 != (char *)0x0) {
      _Var4 = parse_method(pool,pcVar6);
      if (!_Var4) {
        json = json_loads(pcVar6,0,&err);
        free(pcVar6);
        pjVar7 = json_object_get(json,DAT_00014c10);
        json_00 = json_object_get(json,DAT_00014c14);
        if ((pjVar7 == (json_t *)0x0) || (pjVar7->type == JSON_FALSE)) {
          if (json_00 != (json_t *)0x0) goto LAB_00014ae8;
          puVar8 = (undefined4 *)malloc(0x11);
          ss = (char *)0x0;
          if (puVar8 != (undefined4 *)0x0) {
            uVar9 = DAT_00014c40[1];
            uVar11 = DAT_00014c40[2];
            uVar14 = DAT_00014c40[3];
            uVar16 = DAT_00014c40[4];
            *puVar8 = *DAT_00014c40;
            puVar8[1] = uVar9;
            puVar8[2] = uVar11;
            puVar8[3] = uVar14;
            *(char *)(puVar8 + 4) = (char)uVar16;
            ss = (char *)puVar8;
          }
        }
        else {
          if ((json_00 == (json_t *)0x0) || (json_00->type == JSON_NULL)) {
            if (((*DAT_00014c18 != '\0') || (*DAT_00014c1c != '\0')) || (5 < *DAT_00014c20)) {
              snprintf(tmp42,0x800,DAT_00014c28,pool->pool_no);
              _applog(6,tmp42,false);
            }
            puVar3 = DAT_00014c30;
            piVar2 = DAT_00014c2c;
            pool->probed = true;
            iVar10 = *piVar2;
            *puVar3 = 1;
            pcVar6 = DAT_00014c3c;
            if (iVar10 != 0) {
              *piVar1 = *piVar1 + 1;
              sprintf(s,pcVar6);
              sVar5 = strlen(s);
              stratum_send(pool,s,sVar5);
            }
            pcVar6 = DAT_00014c38;
            _Var4 = true;
            if (*DAT_00014c34 != 0) {
              _Var4 = true;
              *piVar1 = *piVar1 + 1;
              sprintf(s,pcVar6);
              sVar5 = strlen(s);
              stratum_send(pool,s,sVar5);
            }
            goto out;
          }
LAB_00014ae8:
          ss = json_dumps(json_00,3);
        }
        if (((*DAT_00014c18 != '\0') || (*DAT_00014c1c != '\0')) || (5 < *DAT_00014c20)) {
          snprintf(tmp42,0x800,DAT_00014c24,pool->pool_no,ss);
          _applog(6,tmp42,false);
        }
        _Var4 = false;
        free(ss);
        suspend_stratum(pool);
out:
        if (json == (json_t *)0x0) {
          return _Var4;
        }
        if (json->refcount == 0xffffffff) {
          return _Var4;
        }
        sVar13 = json->refcount - 1;
        json->refcount = sVar13;
        if (sVar13 != 0) {
          return _Var4;
        }
        json_delete(json);
        return _Var4;
      }
      free(pcVar6);
    }
  }
  return false;
}

