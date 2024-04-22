
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

char * parse_config(json_t *config,_Bool fileconf)

{
  int *piVar1;
  int iVar2;
  char *__s;
  char *name;
  char *p;
  json_t *val;
  size_t sVar3;
  json_t *json;
  json_t *arr_val;
  char *pcVar4;
  char *str;
  char *pcVar5;
  json_t *pjVar6;
  char *pcVar7;
  int iVar8;
  size_t index;
  char tmp42 [2048];
  
  if ((fileconf) && (*(int *)(DAT_0001e72c + 0x414) == 0)) {
    *(undefined4 *)(DAT_0001e72c + 0x414) = 1;
  }
  pcVar7 = DAT_0001e758;
  iVar2 = DAT_0001e72c;
  iVar8 = DAT_0001e730[1];
  piVar1 = DAT_0001e730;
  do {
    if (iVar8 == 0x10) {
      pjVar6 = json_object_get(config,DAT_0001e754);
      if (pjVar6 != (json_t *)0x0) {
        if (pjVar6->type == JSON_STRING) {
          pcVar7 = json_string_value(pjVar6);
          pjVar6 = (json_t *)load_config(pcVar7,(void *)0x0);
        }
        else {
          pjVar6 = (json_t *)0x0;
        }
      }
      return (char *)pjVar6;
    }
    if (iVar8 << 0x1c < 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail(DAT_0001e740,DAT_0001e744,0x75f,DAT_0001e748);
    }
    if (*piVar1 != 0) {
      __s = (char *)__strdup();
      name = strtok(__s,DAT_0001e734);
      while (name != (char *)0x0) {
        if ((name[1] == '-') && (pjVar6 = json_object_get(config,name + 2), pjVar6 != (json_t *)0x0)
           ) {
          if ((*(uint *)((int)piVar1 + 4) & 6) == 0) {
LAB_0001e5b8:
            pcVar5 = DAT_0001e738;
            if (((int)(*(uint *)((int)piVar1 + 4) << 0x1f) < 0) && (pjVar6->type == JSON_TRUE)) {
              pcVar5 = (char *)(**(code **)((int)piVar1 + 8))(*(int *)((int)piVar1 + 0x14));
              goto joined_r0x0001e6e6;
            }
          }
          else {
            if (pjVar6->type != JSON_STRING) {
              if (pjVar6->type == JSON_ARRAY) {
                index = 0;
                while ((sVar3 = json_array_size(pjVar6), index < sVar3 &&
                       (json = json_array_get(pjVar6,index), json != (json_t *)0x0))) {
                  if (json->type == JSON_STRING) {
                    pcVar4 = json_string_value(json);
                    pcVar5 = (char *)(**(code **)((int)piVar1 + 0xc))
                                               (pcVar4,*(int *)((int)piVar1 + 0x14));
                    if (*(int *)((int)piVar1 + 4) == 4) {
                      opt_set_charp(pcVar4,*(char ***)((int)piVar1 + 0x14));
                    }
joined_r0x0001e6b2:
                    if (pcVar5 != (char *)0x0) goto joined_r0x0001e66c;
                  }
                  else if (json->type == JSON_OBJECT) {
                    pcVar5 = parse_config(json,false);
                    goto joined_r0x0001e6b2;
                  }
                  index = index + 1;
                }
                goto LAB_0001e580;
              }
              goto LAB_0001e5b8;
            }
            pcVar4 = json_string_value(pjVar6);
            pcVar5 = (char *)(**(code **)((int)piVar1 + 0xc))(pcVar4,*(int *)((int)piVar1 + 0x14));
            if (*(int *)((int)piVar1 + 4) == 4) {
              opt_set_charp(pcVar4,*(char ***)((int)piVar1 + 0x14));
            }
joined_r0x0001e6e6:
            if (pcVar5 == (char *)0x0) goto LAB_0001e580;
          }
joined_r0x0001e66c:
          if (!fileconf) {
            snprintf((char *)DAT_0001e74c,200,DAT_0001e750,name,pcVar5);
            return (char *)DAT_0001e74c;
          }
          if (((*pcVar7 != '\0') || (opt_log_output != false)) || (2 < opt_log_level)) {
            snprintf(tmp42,0x800,DAT_0001e73c,name,pcVar5);
            _applog(3,tmp42,false);
          }
          *(undefined4 *)(iVar2 + 0x414) = 0xffffffff;
        }
LAB_0001e580:
        name = strtok((char *)0x0,DAT_0001e734);
      }
      free(__s);
    }
    iVar8 = *(int *)((int)piVar1 + 0x20);
    piVar1 = (int *)((int)piVar1 + 0x1c);
  } while( true );
}

