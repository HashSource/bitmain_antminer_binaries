
/* WARNING: Unknown calling convention */

_Bool subscribe_extranonce(pool *pool)

{
  _Bool _Var1;
  size_t len;
  char *pcVar2;
  json_t *json;
  json_t *pjVar3;
  json_t *res_val;
  json_t *val;
  json_t *err_val;
  char *ss;
  int iVar4;
  undefined4 *__ptr;
  undefined4 *puVar5;
  char *__retval;
  undefined4 uVar6;
  undefined4 uVar7;
  size_t sVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  json_error_t err;
  char tmp42 [2048];
  char s [8192];
  
  pcVar2 = DAT_00014e38;
  *DAT_00014e34 = *DAT_00014e34 + 1;
  sprintf(s,pcVar2);
  len = strlen(s);
  _Var1 = stratum_send(pool,s,len);
  if (_Var1) {
    while (_Var1 = socket_full(pool,2), _Var1) {
      pcVar2 = recv_line(pool);
      if (pcVar2 == (char *)0x0) goto LAB_00014cdc;
      _Var1 = parse_method(pool,pcVar2);
      if (!_Var1) {
        json = json_loads(pcVar2,0,&err);
        free(pcVar2);
        pjVar3 = json_object_get(json,DAT_00014e4c);
        val = json_object_get(json,DAT_00014e50);
        if ((pjVar3 == (json_t *)0x0) || (pjVar3->type == JSON_FALSE)) {
          if (val != (json_t *)0x0) goto LAB_00014d20;
          puVar5 = (undefined4 *)malloc(0x11);
          __ptr = (undefined4 *)0x0;
          if (puVar5 != (undefined4 *)0x0) {
            uVar6 = DAT_00014e6c[1];
            uVar7 = DAT_00014e6c[2];
            uVar9 = DAT_00014e6c[3];
            uVar10 = DAT_00014e6c[4];
            *puVar5 = *DAT_00014e6c;
            puVar5[1] = uVar6;
            puVar5[2] = uVar7;
            puVar5[3] = uVar9;
            *(char *)(puVar5 + 4) = (char)uVar10;
            __ptr = puVar5;
          }
LAB_00014d50:
          if (((*DAT_00014e40 != '\0') || (*DAT_00014e44 != '\0')) || (5 < *DAT_00014e5c)) {
            snprintf(tmp42,0x800,DAT_00014e60,pool->pool_no,__ptr);
            _applog(6,tmp42,false);
          }
          _Var1 = false;
          free(__ptr);
        }
        else {
          if ((val == (json_t *)0x0) || (val->type == JSON_NULL)) {
            if ((*DAT_00014e40 != '\0') || ((*DAT_00014e44 != '\0' || (5 < *DAT_00014e5c)))) {
              iVar4 = pool->pool_no;
              pcVar2 = DAT_00014e68;
LAB_00014db6:
              snprintf(tmp42,0x800,pcVar2,iVar4);
              _Var1 = true;
              _applog(6,tmp42,false);
              goto out;
            }
          }
          else {
LAB_00014d20:
            pcVar2 = __json_array_string(val,1);
            if (((pcVar2 == (char *)0x0) && (pcVar2 = json_string_value(val), pcVar2 == (char *)0x0)
                ) || ((iVar4 = strcmp(pcVar2,DAT_00014e54), iVar4 != 0 &&
                      (iVar4 = strcmp(pcVar2,DAT_00014e58), iVar4 != 0)))) {
              __ptr = (undefined4 *)json_dumps(val,3);
              goto LAB_00014d50;
            }
            if (((*DAT_00014e40 != '\0') || (*DAT_00014e44 != '\0')) || (5 < *DAT_00014e5c)) {
              iVar4 = pool->pool_no;
              pcVar2 = DAT_00014e64;
              goto LAB_00014db6;
            }
          }
          _Var1 = true;
        }
out:
        if (json == (json_t *)0x0) {
          return _Var1;
        }
        if (json->refcount == 0xffffffff) {
          return _Var1;
        }
        sVar8 = json->refcount - 1;
        json->refcount = sVar8;
        if (sVar8 != 0) {
          return _Var1;
        }
        json_delete(json);
        return _Var1;
      }
      free(pcVar2);
    }
    if ((*DAT_00014e3c != '\0') &&
       (((*DAT_00014e40 != '\0' || (*DAT_00014e44 != '\0')) || (6 < *DAT_00014e5c)))) {
      tmp42._0_4_ = *DAT_00014e48;
      tmp42._4_4_ = DAT_00014e48[1];
      tmp42._8_4_ = DAT_00014e48[2];
      tmp42._12_4_ = DAT_00014e48[3];
      tmp42._16_4_ = DAT_00014e48[4];
      tmp42._20_4_ = DAT_00014e48[5];
      tmp42._24_4_ = DAT_00014e48[6];
      tmp42._28_4_ = DAT_00014e48[7];
      tmp42._32_4_ = DAT_00014e48[8];
      tmp42._36_4_ = DAT_00014e48[9];
      tmp42._40_4_ = DAT_00014e48[10];
      tmp42._44_4_ = DAT_00014e48[0xb];
      tmp42._48_4_ = DAT_00014e48[0xc];
      _applog(7,tmp42,false);
    }
    _Var1 = true;
  }
  else {
LAB_00014cdc:
    _Var1 = false;
  }
  return _Var1;
}

