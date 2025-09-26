
undefined4 def_generate_session_id(SSL *param_1,uchar *param_2,uint *param_3)

{
  int iVar1;
  
  iVar1 = RAND_pseudo_bytes(param_2,*param_3);
  if ((0 < iVar1) &&
     ((iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0 ||
      ((iVar1 = RAND_pseudo_bytes(param_2,*param_3), 0 < iVar1 &&
       ((iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0 ||
        ((iVar1 = RAND_pseudo_bytes(param_2,*param_3), 0 < iVar1 &&
         ((iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0 ||
          ((iVar1 = RAND_pseudo_bytes(param_2,*param_3), 0 < iVar1 &&
           ((iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0 ||
            ((iVar1 = RAND_pseudo_bytes(param_2,*param_3), 0 < iVar1 &&
             ((iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0 ||
              ((iVar1 = RAND_pseudo_bytes(param_2,*param_3), 0 < iVar1 &&
               ((iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0 ||
                ((iVar1 = RAND_pseudo_bytes(param_2,*param_3), 0 < iVar1 &&
                 ((iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0 ||
                  ((iVar1 = RAND_pseudo_bytes(param_2,*param_3), 0 < iVar1 &&
                   ((iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0 ||
                    ((iVar1 = RAND_pseudo_bytes(param_2,*param_3), 0 < iVar1 &&
                     ((iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0 ||
                      ((iVar1 = RAND_pseudo_bytes(param_2,*param_3), 0 < iVar1 &&
                       (iVar1 = SSL_has_matching_session_id(param_1,param_2,*param_3), iVar1 == 0)))
                      ))))))))))))))))))))))))))))))))))) {
    return 1;
  }
  return 0;
}

