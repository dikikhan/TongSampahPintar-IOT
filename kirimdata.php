<?php
// koneksi ke database
$konek = mysqli_connect("localhost", "root", "", "dbrubbishlevel");

//baca nilai tinggi yang dikirim oleh esp32
$tinggi = $_GET['tinggi'];

//simpan /update ke tabel tb_tong field tinggi
mysqli_query($konek, "UPDATE tb_tong SET tinggi= '$tinggi'");
