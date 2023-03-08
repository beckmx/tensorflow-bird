
const uint8_t index_custom_html[] = R"=====(

<!doctype html>
<html>

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width,initial-scale=1">   
    <title>TensorFlow ESP32</title>
    <style>
        body {
            font-family: Arial, Helvetica, sans-serif;
            background: #EBEBEB;
            color: #000000;
            font-size: 16px
        }

        h2 {
            font-size: 18px
        }

        section.main {
            display: flex
        }

        #menu,
        section.main {
            flex-direction: column
        }

        #menu {
            display: none;
            flex-wrap: nowrap;
            min-width: 340px;
            background: #2CB6EF;
            padding: 8px;
            border-radius: 4px;
            margin-top: -10px;
            margin-right: 10px
        }

        #content {
            display: flex;
            flex-wrap: wrap;
            align-items: stretch
        }

        figure {
            padding: 0;
            margin: 0;
            -webkit-margin-before: 0;
            margin-block-start: 0;
            -webkit-margin-after: 0;
            margin-block-end: 0;
            -webkit-margin-start: 0;
            margin-inline-start: 0;
            -webkit-margin-end: 0;
            margin-inline-end: 0
        }

        figure img {
            display: block;
            width: 100%;
            height: auto;
            border-radius: 4px;
            margin-top: 8px
        }

        @media (min-width: 800px) and (orientation:landscape) {
            #content {
                display: flex;
                flex-wrap: nowrap;
                align-items: stretch
            }

            figure img {
                display: block;
                max-width: 100%;
                max-height: calc(100vh - 40px);
                width: auto;
                height: auto
            }

            figure {
                padding: 0;
                margin: 0;
                -webkit-margin-before: 0;
                margin-block-start: 0;
                -webkit-margin-after: 0;
                margin-block-end: 0;
                -webkit-margin-start: 0;
                margin-inline-start: 0;
                -webkit-margin-end: 0;
                margin-inline-end: 0
            }
        }

        section#buttons {
            display: flex;
            flex-wrap: nowrap;
            justify-content: space-between
        }

        #nav-toggle {
            cursor: pointer;
            display: block
        }

        #nav-toggle-cb {
            outline: 0;
            opacity: 0;
            width: 0;
            height: 0
        }

        #nav-toggle-cb:checked+#menu {
            display: flex
        }

        .input-group {
            display: flex;
            flex-wrap: nowrap;
            line-height: 22px;
            margin: 5px 0
        }

        .input-group>label {
            display: inline-block;
            padding-right: 10px;
            min-width: 47%
        }

        .input-group input,
        .input-group select {
            flex-grow: 1
        }

        .range-max,
        .range-min {
            display: inline-block;
            padding: 0 5px
        }

        buttona {
            border: none;
            color: #FEFCFB;
            background-color: #0A1128;
            padding: 10px;
            text-align: center;
            display: inline-block;
            border-radius: 4px;    
        }

        #colorDetect { 
            border: none;
            color: #FEFCFB;
            background-color: #0A1128;
            padding: 15px;
            text-align: center;
            display: inline-block;
            font-size: 16px;
            border-radius: 4px;
        }

        #restart {
            border: none;
            color: #FEFCFB;
            background-color: #7B0828;
            padding: 15px;
            text-align: center;
            display: inline-block;
            font-size: 16px;
            border-radius: 4px;  
        }

        button {
            display: block;
            margin: 5px;
            padding: 0 12px;
            border: 0;
            line-height: 28px;
            cursor: pointer;
            color: #fff;
            background: #1bec08;
            border-radius: 5px;
            font-size: 16px;
            outline: 0
        }

        button:hover {
            background: #EB8B13
        }

        button:active {
            background: #EB8B13
        }

        button.disabled {
            cursor: default;
            background: #a0a0a0
        }

        input[type=range] {
            -webkit-appearance: none;
            width: 100%;
            height: 22px;
            background: transparent;
            cursor: pointer;
            margin: 0
        }

        input[type=range]:focus {
            outline: 0
        }

        input[type=range]::-webkit-slider-runnable-track {
            width: 100%;
            height: 2px;
            cursor: pointer;
            background: #EFEFEF;
            border-radius: 0;
            border: 0 solid #EFEFEF
        }

        input[type=range]::-webkit-slider-thumb {
            border: 1px solid rgba(0, 0, 30, 0);
            height: 22px;
            width: 22px;
            border-radius: 50px;
            background: #EB8B13;
            cursor: pointer;
            -webkit-appearance: none;
            margin-top: -11.5px
        }

        input[type=range]:focus::-webkit-slider-runnable-track {
            background: #EFEFEF
        }

        input[type=range]::-moz-range-track {
            width: 100%;
            height: 2px;
            cursor: pointer;
            background: #EFEFEF;
            border-radius: 0;
            border: 0 solid #EFEFEF
        }

        input[type=range]::-moz-range-thumb {
            border: 1px solid rgba(0, 0, 30, 0);
            height: 22px;
            width: 22px;
            border-radius: 50px;
            background: #EB8B13;
            cursor: pointer
        }

        input[type=range]::-ms-track {
            width: 100%;
            height: 2px;
            cursor: pointer;
            background: 0 0;
            border-color: transparent;
            color: transparent
        }

        input[type=range]::-ms-fill-lower {
            background: #EFEFEF;
            border: 0 solid #EFEFEF;
            border-radius: 0
        }

        input[type=range]::-ms-fill-upper {
            background: #EFEFEF;
            border: 0 solid #EFEFEF;
            border-radius: 0
        }

        input[type=range]::-ms-thumb {
            border: 1px solid rgba(0, 0, 30, 0);
            height: 22px;
            width: 22px;
            border-radius: 50px;
            background: #EB8B13;
            cursor: pointer;
            height: 2px
        }

        input[type=range]:focus::-ms-fill-lower {
            background: #EFEFEF
        }

        input[type=range]:focus::-ms-fill-upper {
            background: #363636
        }

        .switch {
            display: block;
            position: relative;
            line-height: 22px;
            font-size: 16px;
            height: 22px
        }

        .switch input {
            outline: 0;
            opacity: 0;
            width: 0;
            height: 0
        }

        .slider {
            width: 50px;
            height: 22px;
            border-radius: 22px;
            cursor: pointer;
            background-color: grey
        }

        .slider,
        .slider:before {
            display: inline-block;
            transition: .4s
        }

        .slider:before {
            position: relative;
            content: "";
            border-radius: 50%;
            height: 16px;
            width: 16px;
            left: 4px;
            top: 3px;
            background-color: #fff
        }

        input:checked+.slider {
            background-color: #EB8B13
        }

        input:checked+.slider:before {
            -webkit-transform: translateX(26px);
            transform: translateX(26px)
        }

        select {
            border: 1px solid #363636;
            font-size: 14px;
            height: 22px;
            outline: 0;
            border-radius: 5px
        }

        .image-container {
            position: relative;
            min-width: 160px; 
        }

        .inference-container {
            position: relative;
            max-width: 400px;
        }

        .output-container {
            position: relative;
            max-width: 400px;
        }

        .output {
            position: relative;
            min-width: 350px;
        }

        .close {
            position: absolute;
            right: 5px;
            top: 5px;
            background: #EB8B13;
            width: 16px;
            height: 16px;
            border-radius: 100px;
            color: #fff;
            text-align: center;
            line-height: 18px;
            cursor: pointer
        }

        .hidden {
            display: none
        }

        .center {
            text-align: center;
        }

        /* CSS Simple Pre Code */
        pre {
            background: #444;
            white-space: pre;
            word-wrap: break-word;
            overflow: scroll;
        }

        pre.code {
            margin: 10px 0px;
            border-radius: 4px;
            border: 1px solid #292929;
            position: relative;
            max-width: 750px;
        }

        pre.code code {
            display: block;
            margin: 0 0 0 5px;
            padding: 15px 16px 14px;
            
            overflow-x: auto;
            font-size: 13px;
            line-height: 19px;
            color: #FEBA06;
        }
        
    </style>
</head>

<body>
    <section class="main">
        <div id="logo">
            <div class="center">
                
                    <img src="data:image/png;base64,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"
                    alt="logo" />
                    <h2 class="bold">Bird Detection on ESP32 Cam</h2>
            </div>          
            <label for="nav-toggle-cb" id="nav-toggle">&#9776;&nbsp;&nbsp;Toggle settings</label>
        </div>
        <div id="content">
            <div id="sidebar">
                <input type="checkbox" id="nav-toggle-cb" checked="checked">
                <nav id="menu">
                    <div class="input-group" id="framesize-group">
                        <label for="framesize">Original Resolution</label>
                        <select id="framesize" class="default-action">
                            <option value="13">UXGA(1600x1200)</option>
                            <option value="12">SXGA(1280x1024)</option>
                            <option value="11">HD(1280x720)</option>
                            <option value="10">XGA(1024x768)</option>
                            <option value="9">SVGA(800x600)</option>
                            <option value="8">VGA(640x480)</option>
                            <option value="7">HVGA(480x320)</option>
                            <option value="6">CIF(400x296)</option>
                            <option value="5">QVGA(320x240)</option>
                            <option value="4" selected>240x240</option>
                            <option value="3">HQVGA(240x176)</option>
                            <option value="2">QCFIF(176x144)</option>
                            <option value="1">QQVGA(160x120)</option>
                            <option value="0">96x96</option>
                        </select>
                    </div>
                    <div class="input-group" id="quality-group">
                        <label for="quality">Quality</label>
                        <div class="range-min">10</div>
                        <input type="range" id="quality" min="10" max="63" value="10" class="default-action">
                        <div class="range-max">63</div>
                    </div>
                    <div class="input-group" id="brightness-group">
                        <label for="brightness">Brightness</label>
                        <div class="range-min">-2</div>
                        <input type="range" id="brightness" min="-2" max="2" value="0" class="default-action">
                        <div class="range-max">2</div>
                    </div>
                    <div class="input-group" id="contrast-group">
                        <label for="contrast">Contrast</label>
                        <div class="range-min">-2</div>
                        <input type="range" id="contrast" min="-2" max="2" value="0" class="default-action">
                        <div class="range-max">2</div>
                    </div>
                    <div class="input-group" id="saturation-group">
                        <label for="saturation">Saturation</label>
                        <div class="range-min">-2</div>
                        <input type="range" id="saturation" min="-2" max="2" value="0" class="default-action">
                        <div class="range-max">2</div>
                    </div>
                    <div class="input-group" id="special_effect-group">
                        <label for="special_effect">Special Effect</label>
                        <select id="special_effect" class="default-action">
                            <option value="0" selected="selected">No Effect</option>
                            <option value="1">Negative</option>
                            <option value="2">Grayscale</option>
                            <option value="3">Red Tint</option>
                            <option value="4">Green Tint</option>
                            <option value="5">Blue Tint</option>
                            <option value="6">Sepia</option>
                        </select>
                    </div>
                    <div class="input-group" id="awb-group">
                        <label for="awb">AWB</label>
                        <div class="switch">
                            <input id="awb" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="awb"></label>
                        </div>
                    </div>
                    <div class="input-group" id="awb_gain-group">
                        <label for="awb_gain">AWB Gain</label>
                        <div class="switch">
                            <input id="awb_gain" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="awb_gain"></label>
                        </div>
                    </div>
                    <div class="input-group" id="wb_mode-group">
                        <label for="wb_mode">WB Mode</label>
                        <select id="wb_mode" class="default-action">
                            <option value="0" selected="selected">Auto</option>
                            <option value="1">Sunny</option>
                            <option value="2">Cloudy</option>
                            <option value="3">Office</option>
                            <option value="4">Home</option>
                        </select>
                    </div>
                    <div class="input-group" id="aec-group">
                        <label for="aec">AEC SENSOR</label>
                        <div class="switch">
                            <input id="aec" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="aec"></label>
                        </div>
                    </div>
                    <div class="input-group" id="aec2-group">
                        <label for="aec2">AEC DSP</label>
                        <div class="switch">
                            <input id="aec2" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="aec2"></label>
                        </div>
                    </div>
                    <div class="input-group" id="ae_level-group">
                        <label for="ae_level">AE Level</label>
                        <div class="range-min">-2</div>
                        <input type="range" id="ae_level" min="-2" max="2" value="0" class="default-action">
                        <div class="range-max">2</div>
                    </div>
                    <div class="input-group" id="aec_value-group">
                        <label for="aec_value">Exposure</label>
                        <div class="range-min">0</div>
                        <input type="range" id="aec_value" min="0" max="1200" value="204" class="default-action">
                        <div class="range-max">1200</div>
                    </div>
                    <div class="input-group" id="agc-group">
                        <label for="agc">AGC</label>
                        <div class="switch">
                            <input id="agc" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="agc"></label>
                        </div>
                    </div>
                    <div class="input-group hidden" id="agc_gain-group">
                        <label for="agc_gain">Gain</label>
                        <div class="range-min">1x</div>
                        <input type="range" id="agc_gain" min="0" max="30" value="5" class="default-action">
                        <div class="range-max">31x</div>
                    </div>
                    <div class="input-group" id="gainceiling-group">
                        <label for="gainceiling">Gain Ceiling</label>
                        <div class="range-min">2x</div>
                        <input type="range" id="gainceiling" min="0" max="6" value="0" class="default-action">
                        <div class="range-max">128x</div>
                    </div>
                    <div class="input-group" id="bpc-group">
                        <label for="bpc">BPC</label>
                        <div class="switch">
                            <input id="bpc" type="checkbox" class="default-action">
                            <label class="slider" for="bpc"></label>
                        </div>
                    </div>
                    <div class="input-group" id="wpc-group">
                        <label for="wpc">WPC</label>
                        <div class="switch">
                            <input id="wpc" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="wpc"></label>
                        </div>
                    </div>
                    <div class="input-group" id="raw_gma-group">
                        <label for="raw_gma">Raw GMA</label>
                        <div class="switch">
                            <input id="raw_gma" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="raw_gma"></label>
                        </div>
                    </div>
                    <div class="input-group" id="lenc-group">
                        <label for="lenc">Lens Correction</label>
                        <div class="switch">
                            <input id="lenc" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="lenc"></label>
                        </div>
                    </div>
                    <div class="input-group" id="hmirror-group">
                        <label for="hmirror">H-Mirror</label>
                        <div class="switch">
                            <input id="hmirror" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="hmirror"></label>
                        </div>
                    </div>
                    <div class="input-group" id="vflip-group">
                        <label for="vflip">V-Flip</label>
                        <div class="switch">
                            <input id="vflip" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="vflip"></label>
                        </div>
                    </div>
                    <div class="input-group" id="dcw-group">
                        <label for="dcw">DCW (Downsize EN)</label>
                        <div class="switch">
                            <input id="dcw" type="checkbox" class="default-action" checked="checked">
                            <label class="slider" for="dcw"></label>
                        </div>
                    </div>
                    <div class="input-group" id="colorbar-group">
                        <label for="colorbar">Color Bar</label>
                        <div class="switch">
                            <input id="colorbar" type="checkbox" class="default-action">
                            <label class="slider" for="colorbar"></label>
                        </div>
                    </div>
                    <!-- <div class="input-group" id="face_detect-group">
                        <label for="face_detect">Face Detection</label>
                        <div class="switch">
                            <input id="face_detect" type="checkbox" class="default-action">
                            <label class="slider" for="face_detect"></label>
                        </div>
                    </div> -->
                    <div class="input-group" id="ei_activate-group">
                        <label for="ei_activate">Bird Detection</label>
                        <div class="switch">
                            <input id="ei_activate" type="checkbox" class="default-action">
                            <label class="slider" for="ei_activate"></label>
                        </div>
                    </div>
                    <section id="buttons">
                        <button id="get-still">Capture Image</button>
                        <button id="toggle-stream">Start Stream </button>
                        <button id="toggle-inference" class="disabled" disabled="disabled">Bird Detect</button>
                        <button id="status">Get status</button>
                    </section>
                </nav>
            </div>
            <figure>
                <div id="stream-container" class="image-container hidden">
                    <div class="close" id="close-stream">×</div>
                    <img id="stream" src="">
                </div>
                <div id="inference-container" class="image-container hidden">
                    <div class="close" id="close-inference">×</div>
                    <img id="inference" src="">
                </div>
                </div>
                <div id="output-container" class="image-container hidden">
                    <p>Output: </p>
                    <div class="output">
                        <pre id="output" class="code"></pre>
                    </div>
                </div>
            </figure>
        </div>
    </section>
    <script>
        document.addEventListener('DOMContentLoaded',
                function () {
                    function b(B) {
                        let C;
                        switch (B.type) {
                            case 'checkbox': C = B.checked ? 1 : 0; break;
                            case 'range': case 'select-one': C = B.value; break;
                            case 'button': case 'submit': C = '1'; break;
                            default: return;
                        }
                        const D = `${c}/control?var=${B.id}&val=${C}`;
                        fetch(D).then(E => { console.log(`request to ${D} finished, status: ${E.status}`) })
                    }
                    var c = document.location.origin;
                    const
                        e = B => { B.classList.add('hidden') },
                        f = B => { B.classList.remove('hidden') },
                        g = B => { B.classList.add('disabled'), B.disabled = !0 },
                        h = B => { B.classList.remove('disabled'), B.disabled = !1 },
                        i = (B, C, D) => { D = !(null != D) || D; let E; 'checkbox' === B.type ? (E = B.checked, C = !!C, B.checked = C) : (E = B.value, B.value = C), D && E !== C ? b(B) : !D && ('aec' === B.id ? C ? e(v) : f(v) : 'agc' === B.id ? C ? (f(t), e(s)) : (e(t), f(s)) : 'awb_gain' === B.id ? C ? f(x) : e(x) : 'ei_activate' === B.id && (C ? h(n) : g(n))) };
                    document.querySelectorAll('.close')
                        .forEach(B => { B.onclick = () => { e(B.parentNode) } }),
                        fetch(`${c}/status`).then(function (B) { return B.json() })
                            .then(function (B) {
                                document.querySelectorAll('.default-action')
                                    .forEach(C => { i(C, B[C.id], !1) })
                            });
                    const
                        j = document.getElementById('stream'),                        
                        k = document.getElementById('stream-container'),
                        ji = document.getElementById('inference'),
                        ki = document.getElementById('inference-container'),
                        l = document.getElementById('get-still'),
                        m = document.getElementById('toggle-stream'),                        
                        n = document.getElementById('toggle-inference'),
                        o = document.getElementById('close-stream'),
                        oi = document.getElementById('close-inference'),
                        ei = document.getElementById('output-container'),                        
                        status = document.getElementById('status'),
                        p = () => { window.stop(), m.innerHTML = 'Start Stream' },
                        pi = () => { window.stop(), n.innerHTML = 'Bird Detect' },
                        q = () => { j.src = `${c + ':9601'}/stream`, f(k), m.innerHTML = 'Stop Stream' };
                        qi = () => { ji.src = `${c}/inference?_cb=${Date.now()}`, f(ki), n.innerHTML = 'Bird Detect' };                                                                                                    
                        l.onclick = () => { p(), j.src = `${c}/capture?_cb=${Date.now()}`, f(k) },
                        o.onclick = () => { p(), e(k) },
                        oi.onclick = () => { pi(), e(ki) }, 
                        m.onclick = () => { const B = 'Stop Stream' === m.innerHTML; B ? p() : q() },                        
                        n.onclick = () => { const B = 'Bird Detect' === m.innerHTML; B ? pi() : qi()}, 
                        ji.addEventListener('load', (event) => {                               
                            function loop() {                                               
                                    console.log('image has been loaded!');                                                                        
                                    httpReq('inference');
                                    httpReq('inference-results');
                                    return ji.src = `${c}/capture?_cb=${Date.now()}`;
                                    window.requestAnimationFrame(loop);                                                                                                                                                
                                  }
                                loop();                                                                                                                                                          
                            },); 
                        status.onclick = () => { httpReq('status') };
                    const r = document.getElementById('agc'),
                        s = document.getElementById('agc_gain-group'),
                        t = document.getElementById('gainceiling-group');
                    r.onchange = () => { b(r), r.checked ? (f(t), e(s)) : (e(t), f(s)) };
                    const u = document.getElementById('aec'),
                        v = document.getElementById('aec_value-group');
                    u.onchange = () => { b(u), u.checked ? e(v) : f(v) };
                    const w = document.getElementById('awb_gain'),
                        x = document.getElementById('wb_mode-group');
                    w.onchange = () => { b(w), w.checked ? f(x) : e(x) };
                    const //y = document.getElementById('face_detect'),
                        z = document.getElementById('ei_activate'),
                        A = document.getElementById('framesize');
                    A.onchange = () => { b(A), 5 < A.value && (i(y, !1), i(z, !1)) },
                        //y.onchange = () => { return 6 < A.value ? (alert('Please select CIF or lower resolution before enabling this feature!'), void i(y, !1)) : void (b(y), !y.checked) }, 
                        z.onchange = () => { return 5 < A.value ? (alert('Please select QVGA or lower resolution before enabling this feature!'), void i(z, !1)) : void (b(z), z.checked ? (h(n)) : g(n)) };

                    
                    function httpReq(endpoint){    
                        fetch(`${window.location.href}`+endpoint)
                        //fetch(`http://192.168.1.198/`+endpoint)
                        .then(data => {return data.json()})
                        .then(res=>{
                            console.log(res); 
                            displayOutput(res)
                        })
                    };
                    
                    function displayOutput(data) {
                        f(ei); 
                        var pre = document.getElementById("output");
                            pre.innerHTML = '';
                        var code = document.createElement("code");
                            code.innerHTML = JSON.stringify(data, null, '\t');
                            pre.appendChild(code);
                    };

                    
                });
        </script>
</body>
</html>
)=====";

size_t index_custom_html_len = sizeof(index_custom_html)-1;
