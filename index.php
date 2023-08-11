<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Monitoring ketinggian sampah dan volume sampah berbasis web</title>

    <link rel="stylesheet" type="text/css" href="css/bootstrap.min.css">
    <script type="text/javascript" src="jquery/jquery.min.js"></script>
    <script type="text/javascript" src="js/bootstrap.min.js"></script>
    <style type="text/css">
        .tong {
            border-style: solid;
            width: 300px;
            height: 300px;
            left: 50%;
            transform: translate(-50%);
            position: sticky;
            border-bottom-left-radius: 20px;
            border-bottom-right-radius: 20px;
        }

        .sampah {
            width: 100%;
            height: 100%;
            left: 50%;
            bottom: 0px;
            transform: translate(-50%);
            position: absolute;
            border-bottom-left-radius: 20px;
            border-bottom-right-radius: 20px;
            background-color: gray;
        }

        .penutup {
            border-style: solid;
            width: 300px;
            height: 40px;
            left: 50%;
            transform: translate(-50%);
            position: sticky;
            border-top-left-radius: 20px;
            border-top-right-radius: 20px;
        }

        .pegangan {
            border-style: solid;
            width: 40px;
            height: 20px;
            left: 50%;
            transform: translate(-50%);
            position: sticky;
            border-top-left-radius: 20px;
            border-top-right-radius: 20px;
        }
    </style>
    <!-- ajax untuk proses realtime-->
    <script type="text/javascript">
        $(document).ready(function() {
            setInterval(function() {
                $("#data").load('data.php')
            }, 1000);
        });
    </script>

</head>

<body>
    <!-- Tampilan Aplikasi-->
    <div class="container" style="text-align:center;">
        <img src="images/Logo polkam politeknik kampar.png" style="width: 120px; margin-top: 25px;">
        <h3>Sistem Monitoring Ketinggian Tong sampah <br> berbasis Web</h3>
        <div style="font-size: 20px;">Tong sampah (Tinggi Max 1 Meter)</div>

        <div id="data"></div>

        <!-- logo-->
        <img src="" style="margin-top: 15 px; ">
    </div>

</body>

</html>