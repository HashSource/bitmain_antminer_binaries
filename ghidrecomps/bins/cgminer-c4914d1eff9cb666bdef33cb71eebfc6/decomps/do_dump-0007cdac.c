
int do_dump(json_t *json,size_t flags,int depth,json_dump_callback_t dump,void *data)

{
  size_t sVar1;
  char *pcVar2;
  json_t *pjVar3;
  void *pvVar4;
  size_t sVar5;
  int iVar6;
  json_int_t jVar7;
  double in_stack_ffffff28;
  json_dump_callback_t dump_local;
  int depth_local;
  size_t flags_local;
  json_t *json_local;
  char buffer [100];
  json_t *value_1;
  char *key;
  char **keys;
  size_t size_2;
  char *key_1;
  void *next;
  json_object_t *object;
  size_t n;
  json_array_t *array;
  int size;
  int size_1;
  double value;
  size_t i_1;
  int separator_length;
  char *separator;
  void *iter;
  size_t i;
  
  if (json == (json_t *)0x0) {
    iVar6 = -1;
  }
  else {
    switch(json->type) {
    case JSON_OBJECT:
      if ((flags & 0x20) == 0) {
        separator = ": ";
        separator_length = 2;
      }
      else {
        separator = ":";
        separator_length = 1;
      }
      if (json[4].refcount == 0) {
        json[4].refcount = 1;
        iter = json_object_iter(json);
        iVar6 = (*dump)("{",1,data);
        if (iVar6 == 0) {
          if (iter == (void *)0x0) {
            json[4].refcount = 0;
            iVar6 = (*dump)("}",1,data);
            return iVar6;
          }
          iVar6 = dump_indent(flags,depth + 1,0,dump,data);
          if (iVar6 == 0) {
            if ((flags & 0x80) == 0) {
              do {
                while( true ) {
                  if (iter == (void *)0x0) goto LAB_0007d394;
                  pvVar4 = json_object_iter_next(json,iter);
                  pcVar2 = json_object_iter_key(iter);
                  sVar5 = strlen(pcVar2);
                  dump_string(pcVar2,sVar5,dump,data,flags);
                  iVar6 = (*dump)(separator,separator_length,data);
                  if (iVar6 != 0) goto object_error;
                  pjVar3 = json_object_iter_value(iter);
                  iVar6 = do_dump(pjVar3,flags,depth + 1,dump,data);
                  if (iVar6 != 0) goto object_error;
                  iter = pvVar4;
                  if (pvVar4 == (void *)0x0) break;
                  iVar6 = (*dump)(",",1,data);
                  if ((iVar6 != 0) || (iVar6 = dump_indent(flags,depth + 1,1,dump,data), iVar6 != 0)
                     ) goto object_error;
                }
                iVar6 = dump_indent(flags,depth,0,dump,data);
              } while (iVar6 == 0);
            }
            else {
              sVar1 = json_object_size(json);
              pvVar4 = jsonp_malloc(sVar1 << 2);
              if (pvVar4 != (void *)0x0) {
                i_1 = 0;
                while (iter != (void *)0x0) {
                  pcVar2 = json_object_iter_key(iter);
                  *(char **)((int)pvVar4 + i_1 * 4) = pcVar2;
                  iter = json_object_iter_next(json,iter);
                  i_1 = i_1 + 1;
                }
                if (i_1 != sVar1) {
                    /* WARNING: Subroutine does not return */
                  __assert_fail("i == size","compat/jansson-2.9/src/dump.c",0x152,"do_dump");
                }
                qsort(pvVar4,sVar1,4,compare_keys + 1);
                i_1 = 0;
                do {
                  if (sVar1 <= i_1) {
                    jsonp_free(pvVar4);
LAB_0007d394:
                    json[4].refcount = 0;
                    iVar6 = (*dump)("}",1,data);
                    return iVar6;
                  }
                  pcVar2 = *(char **)(i_1 * 4 + (int)pvVar4);
                  pjVar3 = json_object_get(json,pcVar2);
                  if (pjVar3 == (json_t *)0x0) {
                    /* WARNING: Subroutine does not return */
                    __assert_fail("value","compat/jansson-2.9/src/dump.c",0x15d,"do_dump");
                  }
                  sVar5 = strlen(pcVar2);
                  dump_string(pcVar2,sVar5,dump,data,flags);
                  iVar6 = (*dump)(separator,separator_length,data);
                  if ((iVar6 != 0) ||
                     (iVar6 = do_dump(pjVar3,flags,depth + 1,dump,data), iVar6 != 0)) {
                    jsonp_free(pvVar4);
                    break;
                  }
                  if (i_1 < sVar1 - 1) {
                    iVar6 = (*dump)(",",1,data);
                    if ((iVar6 != 0) ||
                       (iVar6 = dump_indent(flags,depth + 1,1,dump,data), iVar6 != 0)) {
                      jsonp_free(pvVar4);
                      break;
                    }
                  }
                  else {
                    iVar6 = dump_indent(flags,depth,0,dump,data);
                    if (iVar6 != 0) {
                      jsonp_free(pvVar4);
                      break;
                    }
                  }
                  i_1 = i_1 + 1;
                } while( true );
              }
            }
          }
        }
      }
object_error:
      json[4].refcount = 0;
      iVar6 = -1;
      break;
    case JSON_ARRAY:
      if (json[2].refcount == 0) {
        json[2].refcount = 1;
        sVar1 = json_array_size(json);
        iVar6 = (*dump)("[",1,data);
        if (iVar6 == 0) {
          if (sVar1 == 0) {
            json[2].refcount = 0;
            iVar6 = (*dump)("]",1,data);
            return iVar6;
          }
          iVar6 = dump_indent(flags,depth + 1,0,dump,data);
          if (iVar6 == 0) {
            i = 0;
            while( true ) {
              if (sVar1 <= i) {
                json[2].refcount = 0;
                iVar6 = (*dump)("]",1,data);
                return iVar6;
              }
              pjVar3 = json_array_get(json,i);
              iVar6 = do_dump(pjVar3,flags,depth + 1,dump,data);
              if (iVar6 != 0) break;
              if (i < sVar1 - 1) {
                iVar6 = (*dump)(",",1,data);
                if (iVar6 != 0) break;
                iVar6 = dump_indent(flags,depth + 1,1,dump,data);
              }
              else {
                iVar6 = dump_indent(flags,depth,0,dump,data);
              }
              if (iVar6 != 0) break;
              i = i + 1;
            }
          }
        }
      }
      json[2].refcount = 0;
      iVar6 = -1;
      break;
    case JSON_STRING:
      pcVar2 = json_string_value(json);
      sVar1 = json_string_length(json);
      iVar6 = dump_string(pcVar2,sVar1,dump,data,flags);
      break;
    case JSON_INTEGER:
      jVar7 = json_integer_value(json);
      sVar1 = snprintf(buffer,100,"%lld",(int)jVar7,jVar7);
      if (((int)sVar1 < 0) || (99 < (int)sVar1)) {
        iVar6 = -1;
      }
      else {
        iVar6 = (*dump)(buffer,sVar1,data);
      }
      break;
    case JSON_REAL:
      json_real_value(json);
      sVar1 = jsonp_dtostr(buffer,100,in_stack_ffffff28,flags >> 0xb & 0x1f);
      if ((int)sVar1 < 0) {
        iVar6 = -1;
      }
      else {
        iVar6 = (*dump)(buffer,sVar1,data);
      }
      break;
    case JSON_TRUE:
      iVar6 = (*dump)("true",4,data);
      break;
    case JSON_FALSE:
      iVar6 = (*dump)("false",5,data);
      break;
    case JSON_NULL:
      iVar6 = (*dump)("null",4,data);
      break;
    default:
      iVar6 = -1;
    }
  }
  return iVar6;
}

