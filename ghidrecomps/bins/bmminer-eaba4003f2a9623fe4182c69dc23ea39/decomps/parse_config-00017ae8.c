
char * parse_config(json_t *config,_Bool fileconf)

{
  char *pcVar1;
  size_t sVar2;
  json_t *config_00;
  json_t *pjVar3;
  char *pcVar4;
  _Bool fileconf_local;
  json_t *config_local;
  char tmp42 [2048];
  json_t *arr_val;
  char *str;
  json_t *val;
  char *name;
  size_t index;
  char *err;
  char *p;
  opt_table *opt;
  
  if ((fileconf) && (fileconf_load == 0)) {
    fileconf_load = 1;
  }
  opt = opt_config_table;
  do {
    if (opt->type == OPT_END) {
      pjVar3 = json_object_get(config,"include");
      if (((pjVar3 == (json_t *)0x0) || (pjVar3 == (json_t *)0x0)) || (pjVar3->type != JSON_STRING))
      {
        pcVar4 = (char *)0x0;
      }
      else {
        pcVar4 = json_string_value(pjVar3);
        pcVar4 = load_config(pcVar4,(void *)0x0);
      }
      return pcVar4;
    }
    if ((opt->type & OPT_SUBTABLE) != 0) {
                    /* WARNING: Subroutine does not return */
      __assert_fail("!(opt->type & OPT_SUBTABLE)","cgminer.c",0x766,"parse_config");
    }
    if (opt->names != (char *)0x0) {
      pcVar4 = strdup(opt->names);
      p = strtok(pcVar4,"|");
      while (p != (char *)0x0) {
        err = (char *)0x0;
        if ((p[1] == '-') && (pjVar3 = json_object_get(config,p + 2), pjVar3 != (json_t *)0x0)) {
          if (((opt->type & (OPT_HASARG|OPT_PROCESSARG)) == 0) ||
             ((pjVar3 == (json_t *)0x0 || (pjVar3->type != JSON_STRING)))) {
            if (((opt->type & (OPT_HASARG|OPT_PROCESSARG)) == 0) ||
               ((pjVar3 == (json_t *)0x0 || (pjVar3->type != JSON_ARRAY)))) {
              if (((opt->type & OPT_NOARG) == 0) ||
                 ((pjVar3 == (json_t *)0x0 || (pjVar3->type != JSON_TRUE)))) {
                err = "Invalid value";
              }
              else {
                err = (*opt->cb)((opt->u).carg);
              }
            }
            else {
              index = 0;
              while ((sVar2 = json_array_size(pjVar3), index < sVar2 &&
                     (config_00 = json_array_get(pjVar3,index), config_00 != (json_t *)0x0))) {
                if ((config_00 == (json_t *)0x0) || (config_00->type != JSON_STRING)) {
                  if ((config_00 != (json_t *)0x0) && (config_00->type == JSON_OBJECT)) {
                    err = parse_config(config_00,false);
                  }
                }
                else {
                  pcVar1 = json_string_value(config_00);
                  err = (*opt->cb_arg)(pcVar1,(opt->u).carg);
                  if (opt->type == OPT_PROCESSARG) {
                    opt_set_charp(pcVar1,(char **)(opt->u).carg);
                  }
                }
                if (err != (char *)0x0) break;
                index = index + 1;
              }
            }
          }
          else {
            pcVar1 = json_string_value(pjVar3);
            err = (*opt->cb_arg)(pcVar1,(opt->u).carg);
            if (opt->type == OPT_PROCESSARG) {
              opt_set_charp(pcVar1,(char **)(opt->u).carg);
            }
          }
          if (err != (char *)0x0) {
            if (!fileconf) {
              snprintf(parse_config::err_buf,200,"Parsing JSON option %s: %s",p,err);
              return parse_config::err_buf;
            }
            if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
              snprintf(tmp42,0x800,"Invalid config option %s: %s",p,err);
              _applog(3,tmp42,false);
            }
            fileconf_load = -1;
          }
        }
        p = strtok((char *)0x0,"|");
      }
      free(pcVar4);
    }
    opt = opt + 1;
  } while( true );
}

