
point_conversion_form_t EC_KEY_get_conv_form(EC_KEY *key)

{
  return *(point_conversion_form_t *)(key + 0x14);
}

