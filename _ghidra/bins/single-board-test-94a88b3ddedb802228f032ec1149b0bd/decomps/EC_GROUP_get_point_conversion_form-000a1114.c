
point_conversion_form_t EC_GROUP_get_point_conversion_form(EC_GROUP *param_1)

{
  return *(point_conversion_form_t *)(param_1 + 0x38);
}

