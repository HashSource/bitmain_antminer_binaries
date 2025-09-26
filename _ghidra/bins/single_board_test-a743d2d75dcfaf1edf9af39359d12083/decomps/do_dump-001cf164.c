
/* WARNING: Unknown calling convention */

int do_dump(json_t *json,size_t flags,int depth,hashtable_t *parents,json_dump_callback_t dump,
           void *data)

{
  int iVar1;
  json_t *pjVar2;
  char *pcVar3;
  size_t sVar4;
  void *iter;
  void *pvVar5;
  char *pcVar6;
  size_t sVar7;
  size_t __nmemb;
  uint flags_00;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  double value;
  char loop_key [11];
  
  uVar9 = flags & 0x10000;
  flags_00 = flags & 0xfffeffff;
  if (json != (json_t *)0x0) {
    switch(json->type) {
    case JSON_OBJECT:
      pcVar3 = ":";
      if ((flags & 0x20) == 0) {
        pcVar3 = ": ";
        sVar4 = 2;
      }
      else {
        sVar4 = 1;
      }
      iVar1 = jsonp_loop_check(parents,json,loop_key,0xb);
      if ((iVar1 == 0) &&
         ((iter = json_object_iter(json), uVar9 != 0 || (iVar1 = (*dump)("{",1,data), iVar1 == 0))))
      {
        if (iter != (void *)0x0) {
          iVar11 = depth + 1;
          iVar1 = dump_indent(flags_00,iVar11,0,dump,data);
          if (iVar1 != 0) {
            return -1;
          }
          if ((flags & 0x80) == 0) {
            while( true ) {
              pvVar5 = json_object_iter_next(json,iter);
              pcVar6 = json_object_iter_key(iter);
              sVar7 = strlen(pcVar6);
              dump_string(pcVar6,sVar7,dump,data,flags & 0xfffeffff);
              iVar1 = (*dump)(pcVar3,sVar4,data);
              if (iVar1 != 0) {
                return -1;
              }
              pjVar2 = json_object_iter_value(iter);
              iVar1 = do_dump(pjVar2,flags_00,iVar11,parents,dump,data);
              if (iVar1 != 0) {
                return -1;
              }
              if (pvVar5 == (void *)0x0) break;
              iVar1 = (*dump)(",",1,data);
              if (iVar1 != 0) {
                return -1;
              }
              iVar1 = dump_indent(flags_00,iVar11,1,dump,data);
              iter = pvVar5;
              if (iVar1 != 0) {
                return -1;
              }
            }
            iVar1 = dump_indent(flags_00,depth,0,dump,data);
            if (iVar1 != 0) {
              return -1;
            }
          }
          else {
            __nmemb = json_object_size(json);
            pvVar5 = jsonp_malloc(__nmemb << 2);
            if (pvVar5 == (void *)0x0) {
              return -1;
            }
            puVar13 = (undefined4 *)((int)pvVar5 + -4);
            uVar10 = 0;
            puVar12 = puVar13;
            do {
              uVar8 = uVar10;
              pcVar6 = json_object_iter_key(iter);
              puVar12 = puVar12 + 1;
              *puVar12 = pcVar6;
              iter = json_object_iter_next(json,iter);
              uVar10 = uVar8 + 1;
            } while (iter != (void *)0x0);
            if (__nmemb != uVar10) {
                    /* WARNING: Subroutine does not return */
              __assert_fail("i == size","dump.c",0x14f,"do_dump");
            }
            qsort(pvVar5,__nmemb,4,(__compar_fn_t)0x1cf091);
            if (__nmemb != 0) {
              uVar10 = 0;
              do {
                puVar13 = puVar13 + 1;
                pcVar6 = (char *)*puVar13;
                pjVar2 = json_object_get(json,pcVar6);
                if (pjVar2 == (json_t *)0x0) {
                    /* WARNING: Subroutine does not return */
                  __assert_fail("value","dump.c",0x159,"do_dump");
                }
                sVar7 = strlen(pcVar6);
                dump_string(pcVar6,sVar7,dump,data,flags_00);
                iVar1 = (*dump)(pcVar3,sVar4,data);
                if ((iVar1 != 0) ||
                   (iVar1 = do_dump(pjVar2,flags_00,iVar11,parents,dump,data), iVar1 != 0)) {
LAB_001cf572:
                  jsonp_free(pvVar5);
                  return -1;
                }
                if (uVar10 < uVar8) {
                  iVar1 = (*dump)(",",1,data);
                  if (iVar1 != 0) goto LAB_001cf572;
                  iVar1 = dump_indent(flags_00,iVar11,1,dump,data);
                }
                else {
                  iVar1 = dump_indent(flags_00,depth,0,dump,data);
                }
                if (iVar1 != 0) goto LAB_001cf572;
                uVar10 = uVar10 + 1;
              } while (__nmemb != uVar10);
            }
            jsonp_free(pvVar5);
          }
        }
        hashtable_del(parents,loop_key);
        if (uVar9 != 0) {
          return 0;
        }
        iVar1 = (*dump)("}",1,data);
        return iVar1;
      }
      break;
    case JSON_ARRAY:
      iVar1 = jsonp_loop_check(parents,json,loop_key,0xb);
      if ((iVar1 == 0) &&
         ((sVar4 = json_array_size(json), uVar9 != 0 || (iVar1 = (*dump)("[",1,data), iVar1 == 0))))
      {
        if (sVar4 != 0) {
          iVar11 = depth + 1;
          iVar1 = dump_indent(flags_00,iVar11,0,dump,data);
          if (iVar1 != 0) {
            return -1;
          }
          uVar10 = 0;
          do {
            pjVar2 = json_array_get(json,uVar10);
            iVar1 = do_dump(pjVar2,flags_00,iVar11,parents,dump,data);
            if (iVar1 != 0) {
              return -1;
            }
            if (uVar10 < sVar4 - 1) {
              iVar1 = (*dump)(",",1,data);
              if (iVar1 != 0) {
                return -1;
              }
              iVar1 = dump_indent(flags_00,iVar11,1,dump,data);
            }
            else {
              iVar1 = dump_indent(flags_00,depth,0,dump,data);
            }
            if (iVar1 != 0) {
              return -1;
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 != sVar4);
        }
        hashtable_del(parents,loop_key);
        if (uVar9 != 0) {
          return 0;
        }
        iVar1 = (*dump)("]",1,data);
        return iVar1;
      }
      break;
    case JSON_STRING:
      pcVar3 = json_string_value(json);
      sVar4 = json_string_length(json);
      iVar1 = dump_string(pcVar3,sVar4,dump,data,flags_00);
      return iVar1;
    case JSON_INTEGER:
      json_integer_value(json);
      sVar4 = snprintf(loop_key,100,"%lld");
      if (sVar4 < 100) {
LAB_001cf2ea:
        iVar1 = (*dump)(loop_key,sVar4,data);
        return iVar1;
      }
      break;
    case JSON_REAL:
      value = json_real_value(json);
      sVar4 = jsonp_dtostr(loop_key,100,value,(flags_00 << 0x10) >> 0x1b);
      if (-1 < (int)sVar4) goto LAB_001cf2ea;
      break;
    case JSON_TRUE:
      iVar1 = (*dump)("true",4,data);
      return iVar1;
    case JSON_FALSE:
      iVar1 = (*dump)("false",5,data);
      return iVar1;
    case JSON_NULL:
      iVar1 = (*dump)("null",4,data);
      return iVar1;
    }
  }
  return -1;
}

