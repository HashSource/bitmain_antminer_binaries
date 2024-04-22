
/* WARNING: Unknown calling convention */

int do_dump(json_t *json,size_t flags,int depth,json_dump_callback_t dump,void *data)

{
  object_key *poVar1;
  object_key *poVar2;
  int size;
  int iVar3;
  json_object_t *object;
  void *iter_00;
  void *iter;
  void *pvVar4;
  void *next;
  char *pcVar5;
  json_array_t *array;
  int n;
  json_t *pjVar6;
  char *pcVar7;
  size_t sVar8;
  int size_2;
  size_t size_1;
  size_t sVar9;
  char *separator;
  size_t i;
  _func_int_void_ptr_void_ptr *cmp_func;
  json_t *value;
  size_t sVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  char *key;
  int separator_length;
  double in_stack_ffffff50;
  object_key *keys;
  char buffer [100];
  
  if (json == (json_t *)0x0) goto switchD_0003d82c_caseD_8;
  switch(json->type) {
  case JSON_OBJECT:
    if ((flags & 0x20) == 0) {
      sVar8 = 2;
      pcVar7 = DAT_0003da88;
    }
    else {
      sVar8 = 1;
      pcVar7 = DAT_0003da8c;
    }
    if (json[4].type == JSON_OBJECT) {
      json[4].type = JSON_ARRAY;
      iter_00 = json_object_iter(json);
      iVar3 = (*dump)(DAT_0003da90,1,data);
      if (iVar3 == 0) {
        if (iter_00 == (void *)0x0) {
          json[4].type = JSON_OBJECT;
          iVar3 = (*dump)(DAT_0003dbec,1,data);
          return iVar3;
        }
        iVar12 = depth + 1;
        iVar3 = dump_indent(flags,iVar12,0,dump,data);
        if (iVar3 == 0) {
          if ((flags & 0x180) == 0) {
            while( true ) {
              pvVar4 = json_object_iter_next(json,iter_00);
              pcVar5 = json_object_iter_key(iter_00);
              dump_string(pcVar5,dump,data,flags);
              iVar3 = (*dump)(pcVar7,sVar8,data);
              if (iVar3 != 0) break;
              pjVar6 = json_object_iter_value(iter_00);
              iVar3 = do_dump(pjVar6,flags,iVar12,dump,data);
              if (iVar3 != 0) break;
              if (pvVar4 == (void *)0x0) {
                iVar3 = dump_indent(flags,depth,0,dump,data);
                if (iVar3 == 0) goto LAB_0003da3e;
                break;
              }
              iVar3 = (*dump)(DAT_0003da94,1,data);
              if ((iVar3 != 0) ||
                 (iVar3 = dump_indent(flags,iVar12,1,dump,data), iter_00 = pvVar4, iVar3 != 0))
              break;
            }
          }
          else {
            sVar10 = json_object_size(json);
            size_1 = sVar10 << 3;
            keys = (object_key *)jsonp_malloc(size_1);
            if (keys != (object_key *)0x0) {
              uVar11 = 0;
              do {
                uVar13 = uVar11;
                poVar1 = keys;
                sVar9 = hashtable_iter_serial(iter_00);
                poVar2 = keys;
                poVar1[uVar13].serial = sVar9;
                pcVar5 = json_object_iter_key(iter_00);
                poVar2[uVar13].key = pcVar5;
                iter_00 = json_object_iter_next(json,iter_00);
                uVar11 = uVar13 + 1;
              } while (iter_00 != (void *)0x0);
              if (sVar10 != uVar13 + 1) {
                    /* WARNING: Subroutine does not return */
                __assert_fail(DAT_0003dbfc,DAT_0003dbf4,0x154,DAT_0003dbf8);
              }
              cmp_func = DAT_0003dbe0;
              if ((flags & 0x80) == 0) {
                cmp_func = DAT_0003dc00;
              }
              qsort(keys,sVar10,8,(__compar_fn_t)cmp_func);
              if (sVar10 != 0) {
                uVar11 = 0;
                do {
                  pcVar5 = keys[uVar11].key;
                  pjVar6 = json_object_get(json,pcVar5);
                  if (pjVar6 == (json_t *)0x0) {
                    /* WARNING: Subroutine does not return */
                    __assert_fail(DAT_0003dbf0,DAT_0003dbf4,0x164,DAT_0003dbf8);
                  }
                  dump_string(pcVar5,dump,data,flags);
                  iVar3 = (*dump)(pcVar7,sVar8,data);
                  if ((iVar3 != 0) || (iVar3 = do_dump(pjVar6,flags,iVar12,dump,data), iVar3 != 0))
                  {
LAB_0003db92:
                    _jsonp_free(&keys);
                    goto object_error;
                  }
                  if (uVar11 < uVar13) {
                    iVar3 = (*dump)(DAT_0003dbe4,1,data);
                    if (iVar3 != 0) goto LAB_0003db92;
                    iVar3 = dump_indent(flags,iVar12,1,dump,data);
                  }
                  else {
                    iVar3 = dump_indent(flags,depth,0,dump,data);
                  }
                  if (iVar3 != 0) goto LAB_0003db92;
                  uVar11 = uVar11 + 1;
                } while (sVar10 != uVar11);
              }
              _jsonp_free(&keys);
LAB_0003da3e:
              json[4].type = JSON_OBJECT;
              iVar3 = (*dump)(DAT_0003daa4,1,data);
              return iVar3;
            }
          }
        }
      }
    }
object_error:
    iVar3 = -1;
    json[4].type = JSON_OBJECT;
    break;
  case JSON_ARRAY:
    if (json[2].refcount == 0) {
      json[2].refcount = 1;
      sVar8 = json_array_size(json);
      iVar3 = (*dump)(DAT_0003da98,1,data);
      if (iVar3 == 0) {
        if (sVar8 == 0) {
          json[2].refcount = 0;
          iVar3 = (*dump)(DAT_0003daa8,1,data);
          return iVar3;
        }
        iVar12 = depth + 1;
        iVar3 = dump_indent(flags,iVar12,0,dump,data);
        if (iVar3 == 0) {
          if (0 < (int)sVar8) {
            sVar10 = 0;
            do {
              pjVar6 = json_array_get(json,sVar10);
              iVar3 = do_dump(pjVar6,flags,iVar12,dump,data);
              if (iVar3 != 0) goto array_error;
              if ((int)sVar10 < (int)(sVar8 - 1)) {
                iVar3 = (*dump)(DAT_0003da94,1,data);
                if (iVar3 != 0) goto array_error;
                iVar3 = dump_indent(flags,iVar12,1,dump,data);
              }
              else {
                iVar3 = dump_indent(flags,depth,0,dump,data);
              }
              if (iVar3 != 0) goto array_error;
              sVar10 = sVar10 + 1;
            } while (sVar8 != sVar10);
          }
          json[2].refcount = 0;
          iVar3 = (*dump)(DAT_0003dbe8,1,data);
          return iVar3;
        }
      }
    }
array_error:
    iVar3 = -1;
    json[2].refcount = 0;
    break;
  case JSON_STRING:
    pcVar7 = json_string_value(json);
    iVar3 = dump_string(pcVar7,dump,data,flags);
    break;
  case JSON_INTEGER:
    json_integer_value(json);
    sVar8 = snprintf(buffer,100,DAT_0003da80);
    if (sVar8 < 100) {
LAB_0003da08:
      iVar3 = (*dump)(buffer,sVar8,data);
      return iVar3;
    }
  default:
switchD_0003d82c_caseD_8:
    iVar3 = -1;
    break;
  case JSON_REAL:
    json_real_value(json);
    sVar8 = jsonp_dtostr(buffer,100,in_stack_ffffff50);
    if (-1 < (int)sVar8) goto LAB_0003da08;
    goto switchD_0003d82c_caseD_8;
  case JSON_TRUE:
    iVar3 = (*dump)(DAT_0003da9c,4,data);
    break;
  case JSON_FALSE:
    iVar3 = (*dump)(DAT_0003daa0,5,data);
    break;
  case JSON_NULL:
    iVar3 = (*dump)(DAT_0003da84,4,data);
  }
  return iVar3;
}

