
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

char * parse_config(json_t *config,_Bool fileconf)

{
  int *piVar1;
  char *__s;
  char *pcVar2;
  size_t sVar3;
  json_t *json;
  char *pcVar4;
  json_t *pjVar5;
  char *pcVar6;
  uint index;
  int iVar7;
  char tmp42 [2048];
  
  if ((fileconf) && (fileconf_load == 0)) {
    fileconf_load = 1;
  }
  if (opt_config_table[0].type == OPT_END) {
LAB_0001e6f4:
    pjVar5 = json_object_get(config,"include");
    if (pjVar5 != (json_t *)0x0) {
      if (pjVar5->type == JSON_STRING) {
        pcVar2 = json_string_value(pjVar5);
        pjVar5 = (json_t *)load_config(pcVar2,(void *)0x0);
      }
      else {
        pjVar5 = (json_t *)0x0;
      }
    }
    return (char *)pjVar5;
  }
  if (-1 < (int)(opt_config_table[0].type << 0x1c)) {
    iVar7 = 0x5ffec;
    do {
      if (*(int *)(iVar7 + -0x1c) != 0) {
        __s = (char *)__strdup();
        pcVar2 = strtok(__s,"|");
        while (pcVar2 != (char *)0x0) {
          if ((pcVar2[1] == '-') &&
             (pjVar5 = json_object_get(config,pcVar2 + 2), pjVar5 != (json_t *)0x0)) {
            if ((*(uint *)(iVar7 + -0x18) & 6) == 0) {
LAB_0001e5b8:
              if (((int)(*(uint *)(iVar7 + -0x18) << 0x1f) < 0) && (pjVar5->type == JSON_TRUE)) {
                pcVar6 = (char *)(**(code **)(iVar7 + -0x14))(*(undefined4 *)(iVar7 + -8));
                goto joined_r0x0001e6e6;
              }
              pcVar6 = "Invalid value";
            }
            else {
              if (pjVar5->type != JSON_STRING) {
                if (pjVar5->type == JSON_ARRAY) {
                  index = 0;
                  while ((sVar3 = json_array_size(pjVar5), index < sVar3 &&
                         (json = json_array_get(pjVar5,index), json != (json_t *)0x0))) {
                    if (json->type == JSON_STRING) {
                      pcVar4 = json_string_value(json);
                      pcVar6 = (char *)(**(code **)(iVar7 + -0x10))
                                                 (pcVar4,*(undefined4 *)(iVar7 + -8));
                      if (*(int *)(iVar7 + -0x18) == 4) {
                        opt_set_charp(pcVar4,*(char ***)(iVar7 + -8));
                      }
joined_r0x0001e6b2:
                      if (pcVar6 != (char *)0x0) goto joined_r0x0001e66c;
                    }
                    else if (json->type == JSON_OBJECT) {
                      pcVar6 = parse_config(json,false);
                      goto joined_r0x0001e6b2;
                    }
                    index = index + 1;
                  }
                  goto LAB_0001e580;
                }
                goto LAB_0001e5b8;
              }
              pcVar4 = json_string_value(pjVar5);
              pcVar6 = (char *)(**(code **)(iVar7 + -0x10))(pcVar4,*(undefined4 *)(iVar7 + -8));
              if (*(int *)(iVar7 + -0x18) == 4) {
                opt_set_charp(pcVar4,*(char ***)(iVar7 + -8));
              }
joined_r0x0001e6e6:
              if (pcVar6 == (char *)0x0) goto LAB_0001e580;
            }
joined_r0x0001e66c:
            if (!fileconf) {
              snprintf(parse_config::err_buf,200,"Parsing JSON option %s: %s",pcVar2,pcVar6);
              return parse_config::err_buf;
            }
            if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
              snprintf(tmp42,0x800,"Invalid config option %s: %s",pcVar2,pcVar6);
              _applog(3,tmp42,false);
            }
            fileconf_load = -1;
          }
LAB_0001e580:
          pcVar2 = strtok((char *)0x0,"|");
        }
        free(__s);
      }
      piVar1 = (int *)(iVar7 + 4);
      if (*piVar1 == 0x10) goto LAB_0001e6f4;
      iVar7 = iVar7 + 0x1c;
    } while (-1 < *piVar1 << 0x1c);
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("!(opt->type & OPT_SUBTABLE)","cgminer.c",0x75f,"parse_config");
}

