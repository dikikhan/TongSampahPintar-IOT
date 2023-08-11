// Include library untuk koneksi ke WiFi
#include <WiFi.h>
#include <HTTPClient.h>
#include <Servo.h>

// Definisikan pin yang akan digunakan
#define trigPin 13
#define echoPin 12
#define ledPin 14
#define trigPinServo 26
#define echoPinServo 27
#define servoPin 25

// Variabel untuk menyimpan waktu dan jarak
long durasi;
int jarak;
Servo myservo;

// Konfigurasi WiFi
const char* ssid = "Galaxy A22D253"; // Nama WiFi yang akan digunakan
const char* password = "diki2803";   // Password WiFi
const char* server = "192.168.193.24"; // Alamat IP server

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial
  pinMode(echoPin, INPUT); // Set pin sebagai input untuk sensor ultrasonik
  pinMode(trigPin, OUTPUT); // Set pin sebagai output untuk trigger sensor ultrasonik
  pinMode(trigPinServo, OUTPUT); // Set pin sebagai output untuk trigger sensor servo
  pinMode(echoPinServo, INPUT); // Set pin sebagai input untuk sensor servo
  pinMode(ledPin, OUTPUT); // Set pin sebagai output untuk LED indikator
  myservo.attach(servoPin); // Melampirkan motor servo ke pin
  
  WiFi.hostname("ESP32"); // Menetapkan hostname untuk modul WiFi
  WiFi.begin(ssid, password); // Menghubungkan ke jaringan WiFi
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting..."); // Menampilkan pesan koneksi sedang dilakukan
    digitalWrite(ledPin, LOW); // Matikan LED indikator
    delay(500); // Tunggu selama 500 ms sebelum mencoba lagi
  }

  Serial.println("Connected!"); // Menampilkan pesan ketika koneksi terhubung
  digitalWrite(ledPin, HIGH); // Nyalakan LED indikator
}

void loop() {
  // Mengukur tinggi sampah
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  durasi = pulseIn(echoPin, HIGH); // Mengukur durasi pantulan gelombang ultrasonik
  jarak = durasi * 0.034 / 2; // Menghitung jarak berdasarkan durasi (dalam cm)
  Serial.print(jarak); // Menampilkan jarak ke serial monitor
  
  // Membaca jarak dari sensor servo dan menentukan aksi motor servo
  long durationServo, cmServo;
  digitalWrite(trigPinServo, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinServo, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinServo, LOW);
  durationServo = pulseIn(echoPinServo, HIGH); // Mengukur durasi pantulan gelombang dari sensor servo
  cmServo = durationServo / 58; // Menghitung jarak dari durasi (dalam cm)
  Serial.print(" | ");
  Serial.println(cmServo); // Menampilkan jarak dari sensor servo ke serial monitor
  if (cmServo < 10) {
    // Jarak terlalu dekat dari sensor servo, gerakkan motor servo ke posisi tutup tempat sampah
    myservo.write(0);
  } else {
    // Gerakkan motor servo berdasarkan jarak yang terdeteksi oleh sensor servo
    myservo.write(90);
  }

  // Kirim data ke database melalui HTTP GET request
  WiFiClient client;
  String link = "http://" + String(server) + "/projectIOT/rubbishlevel/Kirimdata.php?tinggi=" + String(jarak);
  HTTPClient http;
  http.begin(client, link);
  http.GET();
  http.end();
  delay(200); // Tunggu selama 200 ms sebelum mengulangi loop
}
