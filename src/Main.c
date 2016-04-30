#include <pebble.h>

static Window *s_main_window;
static GFont s_bit_12;
static BitmapLayer *s_level_bitmap_layer, *s_coin_bitmap_layer;
static GBitmap *s_level_bitmap, *s_coin_bitmap;
static TextLayer *s_time_layer, *s_date_layer, *s_battery_layer, *s_level_layer;

int i_daily_meters;
int level = 0;

int health_get_today_metric(HealthMetric metric) {
  HealthServiceAccessibilityMask mask = health_service_metric_accessible(metric, time_start_of_today(), time(NULL));
  if(mask == HealthServiceAccessibilityMaskAvailable) {
    return (int)health_service_sum_today(metric);
  } else {
    APP_LOG(APP_LOG_LEVEL_ERROR, "Data unavailable!");
    return 0;
  }
}

static void update_steps() {
  // Update step count 
  i_daily_meters = health_get_today_metric(HealthMetricWalkedDistanceMeters);
}

static void update_health() {
  update_steps();  
  
  APP_LOG(APP_LOG_LEVEL_INFO, "Daily Meters: %d", i_daily_meters);
  
  int new_level;
  
  if (i_daily_meters > 5472)
    new_level = 99;
  else if (i_daily_meters > 5171)
    new_level = 84;
  else if (i_daily_meters > 4983)
    new_level = 83;    
  else if (i_daily_meters > 4795)
    new_level = 82;    
  else if (i_daily_meters > 4476)
    new_level = 81;    
  else if (i_daily_meters > 4293)
    new_level = 74;    
  else if (i_daily_meters > 4099)
    new_level = 73;    
  else if (i_daily_meters > 3941)
    new_level = 72;    
  else if (i_daily_meters > 3784)
    new_level = 71;    
  else if (i_daily_meters > 3653)
    new_level = 64;    
  else if (i_daily_meters > 3506)
    new_level = 63;    
  else if (i_daily_meters > 3318)
    new_level = 62;    
  else if (i_daily_meters > 3154)
    new_level = 61;    
  else if (i_daily_meters > 3023)
    new_level = 54;    
  else if (i_daily_meters > 2888)
    new_level = 53;    
  else if (i_daily_meters > 2713)
    new_level = 52;    
  else if (i_daily_meters > 2540)
    new_level = 51;    
  else if (i_daily_meters > 2382)
    new_level = 44;        
  else if (i_daily_meters > 2252)
    new_level = 43;    
  else if (i_daily_meters > 2069)
    new_level = 42;    
  else if (i_daily_meters > 1874)
    new_level = 41;    
  else if (i_daily_meters > 1743)
    new_level = 34;    
  else if (i_daily_meters > 1609)
    new_level = 33;    
  else if (i_daily_meters > 1427)
    new_level = 32;    
  else if (i_daily_meters > 1252)
    new_level = 31;    
  else if (i_daily_meters > 1121)
    new_level = 24;    
  else if (i_daily_meters > 927)
    new_level = 23;    
  else if (i_daily_meters > 769)
    new_level = 22;    
  else if (i_daily_meters > 595)
    new_level = 21;    
  else if (i_daily_meters > 464)
    new_level = 14;    
  else if (i_daily_meters > 329)
    new_level = 13;    
  else if (i_daily_meters > 173)
    new_level = 12;    
  else
    new_level = 11;
    
  if (new_level != level) {
    gbitmap_destroy(s_level_bitmap);
    level = new_level;
    switch(level) {
      case 11:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_11);
        text_layer_set_text(s_level_layer, "1-1");
        break;
      case 12:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_12);
        text_layer_set_text(s_level_layer, "1-2");
        break;
      case 13:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_13);
        text_layer_set_text(s_level_layer, "1-3");
        break;
      case 14:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_14);
        text_layer_set_text(s_level_layer, "1-4");
        break;
      case 21:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_21);
        text_layer_set_text(s_level_layer, "2-1");
        break;
      case 22:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_22);
        text_layer_set_text(s_level_layer, "2-2");
        break;
      case 23:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_23);
        text_layer_set_text(s_level_layer, "2-3");
        break;
      case 24:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_24);
        text_layer_set_text(s_level_layer, "2-4");
        break;
      case 31:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_31);
        text_layer_set_text(s_level_layer, "3-1");
        break;
      case 32:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_32);
        text_layer_set_text(s_level_layer, "3-2");
        break;
      case 33:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_33);
        text_layer_set_text(s_level_layer, "3-3");
        break;
      case 34:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_34);
        text_layer_set_text(s_level_layer, "3-4");
        break;
      case 41:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_41);
        text_layer_set_text(s_level_layer, "4-1");
        break;
      case 42:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_42);
        text_layer_set_text(s_level_layer, "4-2");
        break;
      case 43:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_43);
        text_layer_set_text(s_level_layer, "4-3");
        break;
      case 44:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_44);
        text_layer_set_text(s_level_layer, "4-4");
        break;
      case 51:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_51);
        text_layer_set_text(s_level_layer, "5-1");
        break;
      case 52:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_52);
        text_layer_set_text(s_level_layer, "5-2");
        break;
      case 53:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_53);
        text_layer_set_text(s_level_layer, "5-3");
        break;
      case 54:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_54);
        text_layer_set_text(s_level_layer, "5-4");
        break;
      case 61:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_61);
        text_layer_set_text(s_level_layer, "6-1");
        break;
      case 62:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_62);
        text_layer_set_text(s_level_layer, "6-2");
        break;
      case 63:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_63);
        text_layer_set_text(s_level_layer, "6-3");
        break;
      case 64:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_64);
        text_layer_set_text(s_level_layer, "6-4");
        break;
      case 71:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_71);
        text_layer_set_text(s_level_layer, "7-1");
        break;
      case 72:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_72);
        text_layer_set_text(s_level_layer, "7-2");
        break;
      case 73:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_73);
        text_layer_set_text(s_level_layer, "7-3");
        break;
      case 74:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_74);
        text_layer_set_text(s_level_layer, "7-4");
        break;
      case 81:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_81);
        text_layer_set_text(s_level_layer, "8-1");
        break;
      case 82:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_82);
        text_layer_set_text(s_level_layer, "8-2");
        break;
      case 83:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_83);
        text_layer_set_text(s_level_layer, "8-3");
        break;
      case 84:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_84);
        text_layer_set_text(s_level_layer, "8-4");
        break;
      case 99:
        s_level_bitmap = gbitmap_create_with_resource(RESOURCE_ID_End);
        text_layer_set_text(s_level_layer, "END");
        break;      
    }
    bitmap_layer_set_bitmap(s_level_bitmap_layer, s_level_bitmap);
  }
    
}

static void update_minute() {    
  // Get a tm structure
  time_t temp = time(NULL); 
  struct tm *tick_time = localtime(&temp);

  // Create a long-lived buffer
  static char buffer[] = "00:00";

  // Write the current hours and minutes into the buffer
  if(clock_is_24h_style() == true) {
    // Use 24 hour format
    strftime(buffer, sizeof("00:00"), "%H:%M", tick_time);
  } else {
    // Use 12 hour format
    strftime(buffer, sizeof("00:00"), "%I:%M", tick_time);
  }

  // Display this time on the TextLayer
  text_layer_set_text(s_time_layer, buffer);
  
  // Write the current month and day into buffers and display to TextLayer
  static char date_buffer[16];
  //strftime(date_buffer, sizeof(date_buffer), "%a %d %b", tick_time); 
  strftime(date_buffer, sizeof(date_buffer), "%b %d", tick_time); 
  text_layer_set_text(s_date_layer, date_buffer); 
}

static void minute_handler(struct tm *tick_time, TimeUnits units_changed) {
  APP_LOG(APP_LOG_LEVEL_INFO, "Minute Handler");
  update_minute();  
}

static void battery_handler(BatteryChargeState new_state) {
  // Write to buffer and display
  static char s_battery_buffer[32];
   
  // Not quite enough rooom for three digits
  if (new_state.charge_percent == 100)
    new_state.charge_percent = 99;
   
  snprintf(s_battery_buffer, sizeof(s_battery_buffer), "X%d", new_state.charge_percent);
  text_layer_set_text(s_battery_layer, s_battery_buffer);
}

static void main_window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  
  // Format layout for rectangle and round Pebbles
  #if defined(PBL_RECT)
    s_date_layer = text_layer_create(GRect(3, 3, 76, 15));
    s_time_layer = text_layer_create(GRect(3, 18, 76, 15));
  
    s_coin_bitmap_layer = bitmap_layer_create(GRect(87, 3, 15, 15));
    s_battery_layer = text_layer_create(GRect(102, 3, 39, 15));
    s_level_layer = text_layer_create(GRect(87, 18, 65, 15));
  
    s_level_bitmap_layer = bitmap_layer_create(GRect(0, 33, 144, 135));
  
    text_layer_set_text_alignment(s_date_layer, GTextAlignmentLeft);
  #elif defined(PBL_ROUND) 
    s_level_bitmap_layer = bitmap_layer_create(GRect(0, 45, 180, 135));  
  
    s_date_layer = text_layer_create(GRect(0, 30, 180, 15));
    s_time_layer = text_layer_create(GRect(0, 15, 180, 15));
  
    s_coin_bitmap_layer = bitmap_layer_create(GRect(70, 150, 15, 15));
    s_battery_layer = text_layer_create(GRect(85, 150, 39, 15));
    s_level_layer = text_layer_create(GRect(0, 165, 180, 15));      
  
    text_layer_set_text_alignment(s_date_layer, GTextAlignmentCenter);
  #endif 
  
  // Window 
  window_set_background_color(s_main_window, GColorBlack);
  
  // Level Bitmap (changes based on steps)
  bitmap_layer_set_background_color(s_level_bitmap_layer, GColorBlack);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_level_bitmap_layer));
     
  // Font
  s_bit_12 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_BIT_12));
  
  // Date Text
  text_layer_set_background_color(s_date_layer, GColorBlack);
  text_layer_set_text_color(s_date_layer, GColorWhite);
  text_layer_set_font(s_date_layer, s_bit_12);
  layer_add_child(window_layer, text_layer_get_layer(s_date_layer));
  
  // Time Text
  text_layer_set_background_color(s_time_layer, GColorBlack);
  text_layer_set_text_color(s_time_layer, GColorWhite);
  text_layer_set_font(s_time_layer, s_bit_12);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_time_layer));
  
  // Coin Bitmap
  bitmap_layer_set_background_color(s_coin_bitmap_layer, GColorBlack);
  layer_add_child(window_layer, bitmap_layer_get_layer(s_coin_bitmap_layer));
  s_coin_bitmap = gbitmap_create_with_resource(RESOURCE_ID_Coin);
  bitmap_layer_set_bitmap(s_coin_bitmap_layer, s_coin_bitmap); 
  
  // Battery Text
  text_layer_set_background_color(s_battery_layer, GColorBlack);
  text_layer_set_text_color(s_battery_layer, GColorWhite);
  text_layer_set_font(s_battery_layer, s_bit_12);
  text_layer_set_text_alignment(s_battery_layer, GTextAlignmentLeft);
  layer_add_child(window_layer, text_layer_get_layer(s_battery_layer));
  
  // Level Text (changes based on steps)
  text_layer_set_background_color(s_level_layer, GColorBlack);
  text_layer_set_text_color(s_level_layer, GColorWhite);
  text_layer_set_font(s_level_layer, s_bit_12);
  text_layer_set_text_alignment(s_level_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(s_level_layer));  
  
  // Get the current battery level
  battery_handler(battery_state_service_peek());    
}

static void main_window_unload(Window *window) {
  // Bitmap
  gbitmap_destroy(s_level_bitmap);  
  gbitmap_destroy(s_coin_bitmap);
  bitmap_layer_destroy(s_level_bitmap_layer);   
  bitmap_layer_destroy(s_coin_bitmap_layer);   
  // Text
  text_layer_destroy(s_time_layer);
  text_layer_destroy(s_date_layer);
  text_layer_destroy(s_battery_layer);
  text_layer_destroy(s_level_layer);
  // Font
  fonts_unload_custom_font(s_bit_12);
}

static void health_handler(HealthEventType event, void *context) {
  // Check health event
  switch(event) {
    case HealthEventSignificantUpdate:
      APP_LOG(APP_LOG_LEVEL_INFO, "New HealthService HealthEventSignificantUpdate event");
      update_health();
      break;
    case HealthEventMovementUpdate:
      APP_LOG(APP_LOG_LEVEL_INFO, "New HealthService HealthEventMovementUpdate event");
      update_health();
      break;
    case HealthEventSleepUpdate:
      APP_LOG(APP_LOG_LEVEL_INFO, "New HealthService HealthEventSleepUpdate event");
      break;
  }  
}

static void init() {
  // Create main Window element and assign to pointer
  s_main_window = window_create();

  // Set handlers to manage the elements inside the Window
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });

  // Use white for round to fill in missing space
  window_set_background_color(s_main_window, PBL_IF_ROUND_ELSE(GColorWhite, GColorWhite));
  
  // Show the Window on the watch, with animated=true
  window_stack_push(s_main_window, true);
  
  // Register with TickTimerService for minutes
  tick_timer_service_subscribe(MINUTE_UNIT, minute_handler);  
  
  // Don't wait for event to fire - load time on startup
  update_minute();  
  
  // Register for battery level updates
  battery_state_service_subscribe(battery_handler);
  
  // Ensure battery level is displayed from the start
  battery_handler(battery_state_service_peek());    
  
  #if defined(PBL_HEALTH)
  // Attempt to subscribe 
  if(!health_service_events_subscribe(health_handler, NULL)) {
    APP_LOG(APP_LOG_LEVEL_ERROR, "Health not available!");
  }
  #else
    APP_LOG(APP_LOG_LEVEL_ERROR, "Health not available!");
  #endif  
}

static void deinit() {
  // Destroy Window
  window_destroy(s_main_window);
  
  // Unsubscribe from subscriptions
  tick_timer_service_unsubscribe();
  battery_state_service_unsubscribe();
  //connection_service_unsubscribe();
  #if defined(PBL_HEALTH)
  health_service_events_unsubscribe();
  #endif
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}