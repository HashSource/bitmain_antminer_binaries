
/* WARNING: Unknown calling convention */

json_t * do_deep_copy(json_t *json,hashtable_t *parents)

{
  bool bVar1;
  int iVar2;
  json_t *pjVar3;
  void *iter;
  char *key;
  json_t *pjVar4;
  size_t sVar5;
  size_t *psVar6;
  uint uVar7;
  char loop_key [11];
  
  if (json == (json_t *)0x0) {
    return (json_t *)0x0;
  }
  switch(json->type) {
  case JSON_OBJECT:
    iVar2 = jsonp_loop_check(parents,json,loop_key,0xb);
    if (iVar2 == 0) {
      pjVar3 = json_object();
      if (pjVar3 == (json_t *)0x0) {
LAB_000d3f36:
        pjVar3 = (json_t *)0x0;
      }
      else {
        iter = json_object_iter(json);
        if (iter != (void *)0x0) {
LAB_000d3eea:
          key = json_object_iter_key(iter);
          pjVar4 = json_object_iter_value(iter);
          pjVar4 = do_deep_copy(pjVar4,parents);
          iVar2 = json_object_set_new_nocheck(pjVar3,key,pjVar4);
          if (iVar2 == 0) goto LAB_000d3ede;
          if (pjVar3->refcount != 0xffffffff) {
            psVar6 = &pjVar3->refcount;
            DataMemoryBarrier(0x1f);
            do {
              ExclusiveAccess(psVar6);
              sVar5 = *psVar6;
              bVar1 = (bool)hasExclusiveAccess(psVar6);
            } while (!bVar1);
            *psVar6 = sVar5 - 1;
            if (sVar5 - 1 == 0) {
              json_delete(pjVar3);
              pjVar3 = (json_t *)0x0;
              goto LAB_000d3f38;
            }
          }
          goto LAB_000d3f36;
        }
      }
LAB_000d3f38:
      hashtable_del(parents,loop_key);
      return pjVar3;
    }
  default:
switchD_000d3e62_default:
    json = (json_t *)0x0;
    break;
  case JSON_ARRAY:
    iVar2 = jsonp_loop_check(parents,json,loop_key,0xb);
    if (iVar2 == 0) {
      pjVar3 = json_array();
      if (pjVar3 != (json_t *)0x0) {
        if ((json->type != JSON_ARRAY) || (json[1].refcount == 0)) goto LAB_000d3e92;
        pjVar4 = (json_t *)0x0;
        uVar7 = 0;
        if (json[1].refcount != 0) goto LAB_000d3f96;
        while( true ) {
          pjVar4 = do_deep_copy(pjVar4,parents);
          iVar2 = json_array_append_new(pjVar3,pjVar4);
          if (iVar2 != 0) break;
          if (json->type != JSON_ARRAY) goto LAB_000d3e92;
          uVar7 = uVar7 + 1;
          if (json[1].refcount <= uVar7) goto LAB_000d3e92;
          pjVar4 = (json_t *)0x0;
          if (uVar7 < json[1].refcount) {
LAB_000d3f96:
            pjVar4 = *(json_t **)(json[2].type + uVar7 * 4);
          }
        }
        if (pjVar3->refcount != 0xffffffff) {
          psVar6 = &pjVar3->refcount;
          DataMemoryBarrier(0x1f);
          do {
            ExclusiveAccess(psVar6);
            sVar5 = *psVar6;
            bVar1 = (bool)hasExclusiveAccess(psVar6);
          } while (!bVar1);
          *psVar6 = sVar5 - 1;
          if (sVar5 - 1 == 0) {
            json_delete(pjVar3);
            pjVar3 = (json_t *)0x0;
            goto LAB_000d3e92;
          }
        }
      }
      pjVar3 = (json_t *)0x0;
LAB_000d3e92:
      hashtable_del(parents,loop_key);
      return pjVar3;
    }
    goto switchD_000d3e62_default;
  case JSON_STRING:
    json = json_stringn_nocheck((char *)json[1].type,json[1].refcount);
    break;
  case JSON_INTEGER:
    json = json_integer((json_int_t)json[1]);
    break;
  case JSON_REAL:
    json = json_real((double)json[1]);
    break;
  case JSON_TRUE:
  case JSON_FALSE:
  case JSON_NULL:
    break;
  }
  return json;
LAB_000d3ede:
  iter = json_object_iter_next(json,iter);
  if (iter == (void *)0x0) goto LAB_000d3f38;
  goto LAB_000d3eea;
}

