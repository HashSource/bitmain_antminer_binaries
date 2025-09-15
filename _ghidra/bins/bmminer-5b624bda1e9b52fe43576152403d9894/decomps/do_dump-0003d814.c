
/* WARNING: Unknown calling convention */

int do_dump(json_t *json,size_t flags,int depth,json_dump_callback_t dump,void *data)

{
  void *pvVar1;
  int iVar2;
  void *iter;
  void *pvVar3;
  char *pcVar4;
  json_t *pjVar5;
  char *pcVar6;
  size_t sVar7;
  size_t sVar8;
  code *__compar;
  size_t sVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  double value;
  void *local_90;
  char buffer [100];
  
  if (json == (json_t *)0x0) goto switchD_0003d82c_default;
  switch(json->type) {
  case JSON_OBJECT:
    pcVar6 = ":";
    if ((flags & 0x20) == 0) {
      sVar7 = 2;
      pcVar6 = ": ";
    }
    else {
      sVar7 = 1;
    }
    if (json[4].type == JSON_OBJECT) {
      json[4].type = JSON_ARRAY;
      iter = json_object_iter(json);
      iVar2 = (*dump)("{",1,data);
      if (iVar2 == 0) {
        if (iter == (void *)0x0) {
          json[4].type = JSON_OBJECT;
          iVar2 = (*dump)("}",1,data);
          return iVar2;
        }
        iVar11 = depth + 1;
        iVar2 = dump_indent(flags,iVar11,0,dump,data);
        if (iVar2 == 0) {
          if ((flags & 0x180) == 0) {
            while( true ) {
              pvVar3 = json_object_iter_next(json,iter);
              pcVar4 = json_object_iter_key(iter);
              dump_string(pcVar4,dump,data,flags);
              iVar2 = (*dump)(pcVar6,sVar7,data);
              if (iVar2 != 0) break;
              pjVar5 = json_object_iter_value(iter);
              iVar2 = do_dump(pjVar5,flags,iVar11,dump,data);
              if (iVar2 != 0) break;
              if (pvVar3 == (void *)0x0) {
                iVar2 = dump_indent(flags,depth,0,dump,data);
                if (iVar2 == 0) goto LAB_0003da3e;
                break;
              }
              iVar2 = (*dump)(",",1,data);
              if ((iVar2 != 0) ||
                 (iVar2 = dump_indent(flags,iVar11,1,dump,data), iter = pvVar3, iVar2 != 0)) break;
            }
          }
          else {
            sVar9 = json_object_size(json);
            local_90 = jsonp_malloc(sVar9 << 3);
            if (local_90 != (void *)0x0) {
              uVar10 = 0;
              do {
                uVar12 = uVar10;
                pvVar3 = local_90;
                sVar8 = hashtable_iter_serial(iter);
                pvVar1 = local_90;
                *(size_t *)((int)pvVar3 + uVar12 * 8) = sVar8;
                pcVar4 = json_object_iter_key(iter);
                *(char **)((int)pvVar1 + uVar12 * 8 + 4) = pcVar4;
                iter = json_object_iter_next(json,iter);
                uVar10 = uVar12 + 1;
              } while (iter != (void *)0x0);
              if (sVar9 != uVar12 + 1) {
                    /* WARNING: Subroutine does not return */
                __assert_fail("i == size","compat/jansson-2.6/src/dump.c",0x154,"do_dump");
              }
              __compar = (code *)0x3d77d;
              if ((flags & 0x80) == 0) {
                __compar = (__compar_fn_t)0x3d611;
              }
              qsort(local_90,sVar9,8,__compar);
              if (sVar9 != 0) {
                uVar10 = 0;
                do {
                  pcVar4 = *(char **)((int)local_90 + uVar10 * 8 + 4);
                  pjVar5 = json_object_get(json,pcVar4);
                  if (pjVar5 == (json_t *)0x0) {
                    /* WARNING: Subroutine does not return */
                    __assert_fail("value","compat/jansson-2.6/src/dump.c",0x164,"do_dump");
                  }
                  dump_string(pcVar4,dump,data,flags);
                  iVar2 = (*dump)(pcVar6,sVar7,data);
                  if ((iVar2 != 0) || (iVar2 = do_dump(pjVar5,flags,iVar11,dump,data), iVar2 != 0))
                  {
LAB_0003db92:
                    _jsonp_free(&local_90);
                    goto LAB_0003d934;
                  }
                  if (uVar10 < uVar12) {
                    iVar2 = (*dump)(",",1,data);
                    if (iVar2 != 0) goto LAB_0003db92;
                    iVar2 = dump_indent(flags,iVar11,1,dump,data);
                  }
                  else {
                    iVar2 = dump_indent(flags,depth,0,dump,data);
                  }
                  if (iVar2 != 0) goto LAB_0003db92;
                  uVar10 = uVar10 + 1;
                } while (sVar9 != uVar10);
              }
              _jsonp_free(&local_90);
LAB_0003da3e:
              json[4].type = JSON_OBJECT;
              iVar2 = (*dump)("}",1,data);
              return iVar2;
            }
          }
        }
      }
    }
LAB_0003d934:
    iVar2 = -1;
    json[4].type = JSON_OBJECT;
    break;
  case JSON_ARRAY:
    if (json[2].refcount == 0) {
      json[2].refcount = 1;
      sVar7 = json_array_size(json);
      iVar2 = (*dump)("[",1,data);
      if (iVar2 == 0) {
        if (sVar7 == 0) {
          json[2].refcount = 0;
          iVar2 = (*dump)("]",1,data);
          return iVar2;
        }
        iVar11 = depth + 1;
        iVar2 = dump_indent(flags,iVar11,0,dump,data);
        if (iVar2 == 0) {
          if (0 < (int)sVar7) {
            sVar9 = 0;
            do {
              pjVar5 = json_array_get(json,sVar9);
              iVar2 = do_dump(pjVar5,flags,iVar11,dump,data);
              if (iVar2 != 0) goto LAB_0003d9dc;
              if ((int)sVar9 < (int)(sVar7 - 1)) {
                iVar2 = (*dump)(",",1,data);
                if (iVar2 != 0) goto LAB_0003d9dc;
                iVar2 = dump_indent(flags,iVar11,1,dump,data);
              }
              else {
                iVar2 = dump_indent(flags,depth,0,dump,data);
              }
              if (iVar2 != 0) goto LAB_0003d9dc;
              sVar9 = sVar9 + 1;
            } while (sVar7 != sVar9);
          }
          json[2].refcount = 0;
          iVar2 = (*dump)("]",1,data);
          return iVar2;
        }
      }
    }
LAB_0003d9dc:
    iVar2 = -1;
    json[2].refcount = 0;
    break;
  case JSON_STRING:
    pcVar6 = json_string_value(json);
    iVar2 = dump_string(pcVar6,dump,data,flags);
    break;
  case JSON_INTEGER:
    json_integer_value(json);
    sVar7 = snprintf(buffer,100,"%lld");
    if (sVar7 < 100) {
LAB_0003da08:
      iVar2 = (*dump)(buffer,sVar7,data);
      return iVar2;
    }
  default:
switchD_0003d82c_default:
    iVar2 = -1;
    break;
  case JSON_REAL:
    value = json_real_value(json);
    sVar7 = jsonp_dtostr(buffer,100,value);
    if (-1 < (int)sVar7) goto LAB_0003da08;
    goto switchD_0003d82c_default;
  case JSON_TRUE:
    iVar2 = (*dump)("true",4,data);
    break;
  case JSON_FALSE:
    iVar2 = (*dump)("false",5,data);
    break;
  case JSON_NULL:
    iVar2 = (*dump)("null",4,data);
  }
  return iVar2;
}

