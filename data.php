<?php
//koneksi ke database
$konek = mysqli_connect("localhost", "root", "", "dbrubbishlevel");
//baca isi tabel tangki
$sql = mysqli_query($konek, "SELECT * FROM tb_tong");
$data = mysqli_fetch_array($sql);

$tinggi_max_tong = 21; // tinggi tong dalam cm
//ukur tinggi sampah
$tinggi_sampah = $tinggi_max_tong - $data['tinggi'];
//prosentase ketinggian sampah
$prosentase_tinggi_sampah = ($tinggi_sampah / $tinggi_max_tong) * 100; //hasil persen
?>

<!-- Pegangan penutup-->
<div class="pegangan"></div>
<!-- Penutup tong sampah-->
<div class="penutup"></div>
<!--Body tong sampah-->
<div class="tong">
    <!-- Tampilan sampah-->
    <div class="sampah" style="width: 100%; height: <?php echo $prosentase_tinggi_sampah; ?>%; color: red">
        <!-- tampilkan informasi tinggi sampah-->
        <?php
        echo "Tinggi Sampah : " . ($tinggi_sampah / 100) . "m";
        ?>

    </div>
</div>