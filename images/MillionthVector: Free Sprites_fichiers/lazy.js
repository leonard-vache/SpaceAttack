(function(){var k,l=this,m=function(a,b,c){a=a.split(".");c=c||l;a[0]in c||!c.execScript||c.execScript("var "+a[0]);for(var d;a.length&&(d=a.shift());)a.length||void 0===b?c=c[d]&&c[d]!==Object.prototype[d]?c[d]:c[d]={}:c[d]=b},p=function(a,b){for(var c=a.split("."),d=b||l,e;e=c.shift();)if(null!=d[e])d=d[e];else return null;return d},q=function(){},aa=function(a){var b=typeof a;if("object"==b)if(a){if(a instanceof Array)return"array";if(a instanceof Object)return b;var c=Object.prototype.toString.call(a);if("[object Window]"==
c)return"object";if("[object Array]"==c||"number"==typeof a.length&&"undefined"!=typeof a.splice&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("splice"))return"array";if("[object Function]"==c||"undefined"!=typeof a.call&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("call"))return"function"}else return"null";else if("function"==b&&"undefined"==typeof a.call)return"object";return b},r=function(a){return"string"==typeof a},t=function(a){return"function"==
aa(a)},ba=function(a){var b=typeof a;return"object"==b&&null!=a||"function"==b},ca=function(a,b,c){return a.call.apply(a.bind,arguments)},da=function(a,b,c){if(!a)throw Error();if(2<arguments.length){var d=Array.prototype.slice.call(arguments,2);return function(){var c=Array.prototype.slice.call(arguments);Array.prototype.unshift.apply(c,d);return a.apply(b,c)}}return function(){return a.apply(b,arguments)}},u=function(a,b,c){u=Function.prototype.bind&&-1!=Function.prototype.bind.toString().indexOf("native code")?
ca:da;return u.apply(null,arguments)},ea=Date.now||function(){return+new Date},v=function(a,b){function c(){}c.prototype=b.prototype;a.yb=b.prototype;a.prototype=new c;a.prototype.constructor=a;a.pb=function(a,c,f){for(var d=Array(arguments.length-2),e=2;e<arguments.length;e++)d[e-2]=arguments[e];return b.prototype[c].apply(a,d)}};var fa=function(a){return function(){return a}}(!0);var w=function(a){if(Error.captureStackTrace)Error.captureStackTrace(this,w);else{var b=Error().stack;b&&(this.stack=b)}a&&(this.message=String(a))};v(w,Error);var x=String.prototype.trim?function(a){return a.trim()}:function(a){return a.replace(/^[\s\xa0]+|[\s\xa0]+$/g,"")},ga=function(a,b){return a<b?-1:a>b?1:0};var ha=Array.prototype.forEach?function(a,b,c){Array.prototype.forEach.call(a,b,c)}:function(a,b,c){for(var d=a.length,e=r(a)?a.split(""):a,f=0;f<d;f++)f in e&&b.call(c,e[f],f,a)},ia=Array.prototype.some?function(a,b,c){return Array.prototype.some.call(a,b,c)}:function(a,b,c){for(var d=a.length,e=r(a)?a.split(""):a,f=0;f<d;f++)if(f in e&&b.call(c,e[f],f,a))return!0;return!1},ja=function(a){return Array.prototype.concat.apply([],arguments)},ka=function(a){var b=a.length;if(0<b){for(var c=Array(b),
d=0;d<b;d++)c[d]=a[d];return c}return[]};var y;a:{var la=l.navigator;if(la){var ma=la.userAgent;if(ma){y=ma;break a}}y=""}var z=function(a){return-1!=y.indexOf(a)};var na=function(a,b){for(var c in a)b.call(void 0,a[c],c,a)},oa="constructor hasOwnProperty isPrototypeOf propertyIsEnumerable toLocaleString toString valueOf".split(" "),pa=function(a,b){for(var c,d,e=1;e<arguments.length;e++){d=arguments[e];for(c in d)a[c]=d[c];for(var f=0;f<oa.length;f++)c=oa[f],Object.prototype.hasOwnProperty.call(d,c)&&(a[c]=d[c])}};var ra=function(a,b){var c=qa;Object.prototype.hasOwnProperty.call(c,a)||(c[a]=b(a))};var sa=z("Opera"),A=z("Trident")||z("MSIE"),ta=z("Edge"),ua=z("Gecko")&&!(-1!=y.toLowerCase().indexOf("webkit")&&!z("Edge"))&&!(z("Trident")||z("MSIE"))&&!z("Edge"),va=-1!=y.toLowerCase().indexOf("webkit")&&!z("Edge"),wa=function(){var a=l.document;return a?a.documentMode:void 0},xa;
a:{var ya="",za=function(){var a=y;if(ua)return/rv\:([^\);]+)(\)|;)/.exec(a);if(ta)return/Edge\/([\d\.]+)/.exec(a);if(A)return/\b(?:MSIE|rv)[: ]([^\);]+)(\)|;)/.exec(a);if(va)return/WebKit\/(\S+)/.exec(a);if(sa)return/(?:Version)[ \/]?(\S+)/.exec(a)}();za&&(ya=za?za[1]:"");if(A){var Aa=wa();if(null!=Aa&&Aa>parseFloat(ya)){xa=String(Aa);break a}}xa=ya}
var Ba=xa,qa={},Ca=function(a){ra(a,function(){for(var b=0,c=x(String(Ba)).split("."),d=x(String(a)).split("."),e=Math.max(c.length,d.length),f=0;0==b&&f<e;f++){var g=c[f]||"",h=d[f]||"";do{g=/(\d*)(\D*)(.*)/.exec(g)||["","","",""];h=/(\d*)(\D*)(.*)/.exec(h)||["","","",""];if(0==g[0].length&&0==h[0].length)break;b=ga(0==g[1].length?0:parseInt(g[1],10),0==h[1].length?0:parseInt(h[1],10))||ga(0==g[2].length,0==h[2].length)||ga(g[2],h[2]);g=g[3];h=h[3]}while(0==b)}return 0<=b})},Da;var Ea=l.document;
Da=Ea&&A?wa()||("CSS1Compat"==Ea.compatMode?parseInt(Ba,10):5):void 0;var C=function(){this.ha={}};C.prototype.register=function(a,b,c){this.ha[a]={la:b,ba:c||fa}};C.prototype.ba=function(a){a=this.ha[a];return!!a&&a.ba()};C.prototype.register=C.prototype.register;m("help.common.helpapiservice.Environment.PROD","https://clients6.google.com",void 0);m("help.common.helpapiservice.Environment.STAGING","https://content-googleapis-staging.sandbox.google.com",void 0);m("help.common.helpapiservice.Environment.TEST","https://content-googleapis-test.sandbox.google.com",void 0);var Fa={hb:"GHELP_SEARCH",gb:"GHELP_AUTOCOMPLETE",ib:"GHELP_SUGGEST",fb:"GHELP_ARTICLE",kb:"LINK",jb:"HELPCENTER",cb:"EMAIL",ab:"CHAT",eb:"FORUM",lb:"MARKETING",nb:"ONEBOX",bb:"CUSTOM",$a:"AUTO",ob:"TESTING"};var Ga;if(!(Ga=!ua&&!A)){var Ha;if(Ha=A)Ha=9<=Number(Da);Ga=Ha}Ga||ua&&Ca("1.9.1");A&&Ca("9");var D=function(){this.qa="";this.Aa=Ia};D.prototype.Ia=!0;var Ia={};var Ka=function(a,b){na(b,function(b,d){b&&b.Ia&&(b=b.qa);"style"==d?a.style.cssText=b:"class"==d?a.className=b:"for"==d?a.htmlFor=b:Ja.hasOwnProperty(d)?a.setAttribute(Ja[d],b):0==d.lastIndexOf("aria-",0)||0==d.lastIndexOf("data-",0)?a.setAttribute(d,b):a[d]=b})},Ja={cellpadding:"cellPadding",cellspacing:"cellSpacing",colspan:"colSpan",frameborder:"frameBorder",height:"height",maxlength:"maxLength",nonce:"nonce",role:"role",rowspan:"rowSpan",type:"type",usemap:"useMap",valign:"vAlign",width:"width"};var E=function(a,b,c){this.La=c;this.Da=a;this.Sa=b;this.ca=0;this.Z=null};E.prototype.get=function(){if(0<this.ca){this.ca--;var a=this.Z;this.Z=a.next;a.next=null}else a=this.Da();return a};E.prototype.put=function(a){this.Sa(a);this.ca<this.La&&(this.ca++,a.next=this.Z,this.Z=a)};var La=function(a){l.setTimeout(function(){throw a;},0)},Ma,Na=function(){var a=l.MessageChannel;"undefined"===typeof a&&"undefined"!==typeof window&&window.postMessage&&window.addEventListener&&!z("Presto")&&(a=function(){var a=document.createElement("IFRAME");a.style.display="none";a.src="";document.documentElement.appendChild(a);var b=a.contentWindow,a=b.document;a.open();a.write("");a.close();var c="callImmediate"+Math.random(),d="file:"==b.location.protocol?"*":b.location.protocol+"//"+b.location.host,
a=u(function(a){if(("*"==d||a.origin==d)&&a.data==c)this.port1.onmessage()},this);b.addEventListener("message",a,!1);this.port1={};this.port2={postMessage:function(){b.postMessage(c,d)}}});if("undefined"!==typeof a&&!z("Trident")&&!z("MSIE")){var b=new a,c={},d=c;b.port1.onmessage=function(){if(void 0!==c.next){c=c.next;var a=c.ua;c.ua=null;a()}};return function(a){d.next={ua:a};d=d.next;b.port2.postMessage(0)}}return"undefined"!==typeof document&&"onreadystatechange"in document.createElement("SCRIPT")?
function(a){var b=document.createElement("SCRIPT");b.onreadystatechange=function(){b.onreadystatechange=null;b.parentNode.removeChild(b);b=null;a();a=null};document.documentElement.appendChild(b)}:function(a){l.setTimeout(a,0)}};var Oa=function(){this.ga=this.S=null},Qa=new E(function(){return new Pa},function(a){a.reset()},100);Oa.prototype.add=function(a,b){var c=Qa.get();c.set(a,b);this.ga?this.ga.next=c:this.S=c;this.ga=c};Oa.prototype.remove=function(){var a=null;this.S&&(a=this.S,this.S=this.S.next,this.S||(this.ga=null),a.next=null);return a};var Pa=function(){this.next=this.scope=this.pa=null};Pa.prototype.set=function(a,b){this.pa=a;this.scope=b;this.next=null};
Pa.prototype.reset=function(){this.next=this.scope=this.pa=null};var Ua=function(a,b){F||Ra();Sa||(F(),Sa=!0);Ta.add(a,b)},F,Ra=function(){if(-1!=String(l.Promise).indexOf("[native code]")){var a=l.Promise.resolve(void 0);F=function(){a.then(Va)}}else F=function(){var a=Va;!t(l.setImmediate)||l.Window&&l.Window.prototype&&!z("Edge")&&l.Window.prototype.setImmediate==l.setImmediate?(Ma||(Ma=Na()),Ma(a)):l.setImmediate(a)}},Sa=!1,Ta=new Oa,Va=function(){for(var a;a=Ta.remove();){try{a.pa.call(a.scope)}catch(b){La(b)}Qa.put(a)}Sa=!1};var Wa=function(a){a.prototype.then=a.prototype.then;a.prototype.$goog_Thenable=!0},Xa=function(a){if(!a)return!1;try{return!!a.$goog_Thenable}catch(b){return!1}};var H=function(a,b){this.j=0;this.s=void 0;this.K=this.u=this.f=null;this.Y=this.oa=!1;if(a!=q)try{var c=this;a.call(b,function(a){G(c,2,a)},function(a){G(c,3,a)})}catch(d){G(this,3,d)}},Ya=function(){this.next=this.context=this.O=this.W=this.C=null;this.X=!1};Ya.prototype.reset=function(){this.context=this.O=this.W=this.C=null;this.X=!1};
var Za=new E(function(){return new Ya},function(a){a.reset()},100),$a=function(a,b,c){var d=Za.get();d.W=a;d.O=b;d.context=c;return d},ab=function(){var a=new H(q);G(a,2,void 0);return a},bb=function(){return new H(function(a,b){b(void 0)})};H.prototype.then=function(a,b,c){return cb(this,t(a)?a:null,t(b)?b:null,c)};Wa(H);var I=function(a){cb(a,null,q,void 0)};H.prototype.cancel=function(a){0==this.j&&Ua(function(){var b=new J(a);db(this,b)},this)};
var db=function(a,b){if(0==a.j)if(a.f){var c=a.f;if(c.u){for(var d=0,e=null,f=null,g=c.u;g&&(g.X||(d++,g.C==a&&(e=g),!(e&&1<d)));g=g.next)e||(f=g);e&&(0==c.j&&1==d?db(c,b):(f?(d=f,d.next==c.K&&(c.K=d),d.next=d.next.next):eb(c),fb(c,e,3,b)))}a.f=null}else G(a,3,b)},hb=function(a,b){a.u||2!=a.j&&3!=a.j||gb(a);a.K?a.K.next=b:a.u=b;a.K=b},cb=function(a,b,c,d){var e=$a(null,null,null);e.C=new H(function(a,g){e.W=b?function(c){try{var e=b.call(d,c);a(e)}catch(B){g(B)}}:a;e.O=c?function(b){try{var e=c.call(d,
b);void 0===e&&b instanceof J?g(b):a(e)}catch(B){g(B)}}:g});e.C.f=a;hb(a,e);return e.C};H.prototype.Ya=function(a){this.j=0;G(this,2,a)};H.prototype.Za=function(a){this.j=0;G(this,3,a)};
var G=function(a,b,c){if(0==a.j){a===c&&(b=3,c=new TypeError("Promise cannot resolve to itself"));a.j=1;a:{var d=c,e=a.Ya,f=a.Za;if(d instanceof H){hb(d,$a(e||q,f||null,a));var g=!0}else if(Xa(d))d.then(e,f,a),g=!0;else{if(ba(d))try{var h=d.then;if(t(h)){ib(d,h,e,f,a);g=!0;break a}}catch(n){f.call(a,n);g=!0;break a}g=!1}}g||(a.s=c,a.j=b,a.f=null,gb(a),3!=b||c instanceof J||jb(a,c))}},ib=function(a,b,c,d,e){var f=!1,g=function(a){f||(f=!0,c.call(e,a))},h=function(a){f||(f=!0,d.call(e,a))};try{b.call(a,
g,h)}catch(n){h(n)}},gb=function(a){a.oa||(a.oa=!0,Ua(a.Ga,a))},eb=function(a){var b=null;a.u&&(b=a.u,a.u=b.next,b.next=null);a.u||(a.K=null);return b};H.prototype.Ga=function(){for(var a;a=eb(this);)fb(this,a,this.j,this.s);this.oa=!1};
var fb=function(a,b,c,d){if(3==c&&b.O&&!b.X)for(;a&&a.Y;a=a.f)a.Y=!1;if(b.C)b.C.f=null,kb(b,c,d);else try{b.X?b.W.call(b.context):kb(b,c,d)}catch(e){lb.call(null,e)}Za.put(b)},kb=function(a,b,c){2==b?a.W.call(a.context,c):a.O&&a.O.call(a.context,c)},jb=function(a,b){a.Y=!0;Ua(function(){a.Y&&lb.call(null,b)})},lb=La,J=function(a){w.call(this,a)};v(J,w);/*
 Portions of this code are from MochiKit, received by
 The Closure Authors under the MIT license. All other code is Copyright
 2005-2009 The Closure Authors. All Rights Reserved.
*/
var K=function(a,b){this.da=[];this.xa=a;this.wa=b||null;this.U=this.L=!1;this.s=void 0;this.ta=this.Ca=this.ja=!1;this.ea=0;this.f=null;this.ka=0};K.prototype.cancel=function(a){if(this.L)this.s instanceof K&&this.s.cancel();else{if(this.f){var b=this.f;delete this.f;a?b.cancel(a):(b.ka--,0>=b.ka&&b.cancel())}this.xa?this.xa.call(this.wa,this):this.ta=!0;this.L||(a=new L,M(this),N(this,!1,a))}};K.prototype.va=function(a,b){this.ja=!1;N(this,a,b)};
var N=function(a,b,c){a.L=!0;a.s=c;a.U=!b;mb(a)},M=function(a){if(a.L){if(!a.ta)throw new nb;a.ta=!1}};K.prototype.la=function(a){M(this);N(this,!0,a)};var ob=function(a,b,c){a.da.push([b,c,void 0]);a.L&&mb(a)};K.prototype.then=function(a,b,c){var d,e,f=new H(function(a,b){d=a;e=b});ob(this,d,function(a){a instanceof L?f.cancel():e(a)});return f.then(a,b,c)};Wa(K);
var pb=function(a){return ia(a.da,function(a){return t(a[1])})},mb=function(a){if(a.ea&&a.L&&pb(a)){var b=a.ea,c=O[b];c&&(l.clearTimeout(c.aa),delete O[b]);a.ea=0}a.f&&(a.f.ka--,delete a.f);for(var b=a.s,d=c=!1;a.da.length&&!a.ja;){var e=a.da.shift(),f=e[0],g=e[1],e=e[2];if(f=a.U?g:f)try{var h=f.call(e||a.wa,b);void 0!==h&&(a.U=a.U&&(h==b||h instanceof Error),a.s=b=h);if(Xa(b)||"function"===typeof l.Promise&&b instanceof l.Promise)d=!0,a.ja=!0}catch(n){b=n,a.U=!0,pb(a)||(c=!0)}}a.s=b;d&&(h=u(a.va,
a,!0),d=u(a.va,a,!1),b instanceof K?(ob(b,h,d),b.Ca=!0):b.then(h,d));c&&(b=new qb(b),O[b.aa]=b,a.ea=b.aa)},nb=function(){w.call(this)};v(nb,w);nb.prototype.message="Deferred has already fired";var L=function(){w.call(this)};v(L,w);L.prototype.message="Deferred was canceled";var qb=function(a){this.aa=l.setTimeout(u(this.Xa,this),0);this.Fa=a};qb.prototype.Xa=function(){delete O[this.aa];throw this.Fa;};var O={};var sb=function(){var a=new D;a.qa="https://ssl.gstatic.com/inproduct_help/guidedhelp/guide_inproduct.js";return rb(a)},rb=function(a){var b={},c=b.document||document;if(a instanceof D&&a.constructor===D&&a.Aa===Ia)var d=a.qa;else aa(a),d="type_error:TrustedResourceUrl";var e=document.createElement("SCRIPT");a={ya:e,za:void 0};var f=new K(tb,a),g=null,h=null!=b.timeout?b.timeout:5E3;0<h&&(g=window.setTimeout(function(){P(e,!0);var a=new ub(1,"Timeout reached for loading script "+d);M(f);N(f,!1,a)},
h),a.za=g);e.onload=e.onreadystatechange=function(){e.readyState&&"loaded"!=e.readyState&&"complete"!=e.readyState||(P(e,b.qb||!1,g),f.la(null))};e.onerror=function(){P(e,!0,g);var a=new ub(0,"Error while loading script "+d);M(f);N(f,!1,a)};a=b.attributes||{};pa(a,{type:"text/javascript",charset:"UTF-8",src:d});Ka(e,a);vb(c).appendChild(e);return f},vb=function(a){var b;return(b=(a||document).getElementsByTagName("HEAD"))&&0!=b.length?b[0]:a.documentElement},tb=function(){if(this&&this.ya){var a=
this.ya;a&&"SCRIPT"==a.tagName&&P(a,!0,this.za)}},P=function(a,b,c){null!=c&&l.clearTimeout(c);a.onload=q;a.onerror=q;a.onreadystatechange=q;b&&window.setTimeout(function(){a&&a.parentNode&&a.parentNode.removeChild(a)},0)},ub=function(a,b){var c="Jsloader error (code #"+a+")";b&&(c+=": "+b);w.call(this,c);this.code=a};v(ub,w);var wb="StopIteration"in l?l.StopIteration:{message:"StopIteration",stack:""},xb=function(){};xb.prototype.next=function(){throw wb;};xb.prototype.Ba=function(){return this};var Q=function(a,b){this.l={};this.c=[];this.fa=this.b=0;var c=arguments.length;if(1<c){if(c%2)throw Error("Uneven number of arguments");for(var d=0;d<c;d+=2)this.set(arguments[d],arguments[d+1])}else a&&this.addAll(a)};Q.prototype.I=function(){yb(this);for(var a=[],b=0;b<this.c.length;b++)a.push(this.l[this.c[b]]);return a};Q.prototype.M=function(){yb(this);return this.c.concat()};Q.prototype.D=function(a){return R(this.l,a)};
Q.prototype.remove=function(a){return R(this.l,a)?(delete this.l[a],this.b--,this.fa++,this.c.length>2*this.b&&yb(this),!0):!1};var yb=function(a){var b,c;if(a.b!=a.c.length){for(b=c=0;c<a.c.length;){var d=a.c[c];R(a.l,d)&&(a.c[b++]=d);c++}a.c.length=b}if(a.b!=a.c.length){var e={};for(b=c=0;c<a.c.length;)d=a.c[c],R(e,d)||(a.c[b++]=d,e[d]=1),c++;a.c.length=b}};k=Q.prototype;k.get=function(a,b){return R(this.l,a)?this.l[a]:b};
k.set=function(a,b){R(this.l,a)||(this.b++,this.c.push(a),this.fa++);this.l[a]=b};k.addAll=function(a){if(a instanceof Q){var b=a.M();a=a.I()}else{b=[];var c=0;for(d in a)b[c++]=d;c=[];var d=0;for(var e in a)c[d++]=a[e];a=c}for(e=0;e<b.length;e++)this.set(b[e],a[e])};k.forEach=function(a,b){for(var c=this.M(),d=0;d<c.length;d++){var e=c[d],f=this.get(e);a.call(b,f,e,this)}};k.clone=function(){return new Q(this)};
k.Ba=function(a){yb(this);var b=0,c=this.fa,d=this,e=new xb;e.next=function(){if(c!=d.fa)throw Error("The map has changed since the iterator was created");if(b>=d.c.length)throw wb;var e=d.c[b++];return a?e:d.l[e]};return e};var R=function(a,b){return Object.prototype.hasOwnProperty.call(a,b)};var zb=/^(?:([^:/?#.]+):)?(?:\/\/(?:([^/?#]*)@)?([^/#?]*?)(?::([0-9]+))?(?=[/#?]|$))?([^?#]+)?(?:\?([^#]*))?(?:#([\s\S]*))?$/,Ab=function(a,b){if(a)for(var c=a.split("&"),d=0;d<c.length;d++){var e=c[d].indexOf("="),f=null;if(0<=e){var g=c[d].substring(0,e);f=c[d].substring(e+1)}else g=c[d];b(g,f?decodeURIComponent(f.replace(/\+/g," ")):"")}};var S=function(a,b){this.o=this.J=this.v="";this.P=null;this.H=this.m="";this.h=this.Ka=!1;if(a instanceof S){this.h=void 0!==b?b:a.h;Bb(this,a.v);var c=a.J;T(this);this.J=c;c=a.o;T(this);this.o=c;Cb(this,a.P);c=a.m;T(this);this.m=c;Db(this,a.i.clone());c=a.H;T(this);this.H=c}else if(a&&(c=String(a).match(zb))){this.h=!!b;Bb(this,c[1]||"",!0);var d=c[2]||"";T(this);this.J=U(d);d=c[3]||"";T(this);this.o=U(d,!0);Cb(this,c[4]);d=c[5]||"";T(this);this.m=U(d,!0);Db(this,c[6]||"",!0);c=c[7]||"";T(this);
this.H=U(c)}else this.h=!!b,this.i=new V(null,0,this.h)};S.prototype.toString=function(){var a=[],b=this.v;b&&a.push(W(b,Eb,!0),":");var c=this.o;if(c||"file"==b)a.push("//"),(b=this.J)&&a.push(W(b,Eb,!0),"@"),a.push(encodeURIComponent(String(c)).replace(/%25([0-9a-fA-F]{2})/g,"%$1")),c=this.P,null!=c&&a.push(":",String(c));if(c=this.m)this.o&&"/"!=c.charAt(0)&&a.push("/"),a.push(W(c,"/"==c.charAt(0)?Fb:Gb,!0));(c=this.i.toString())&&a.push("?",c);(c=this.H)&&a.push("#",W(c,Hb));return a.join("")};
S.prototype.resolve=function(a){var b=this.clone(),c=!!a.v;c?Bb(b,a.v):c=!!a.J;if(c){var d=a.J;T(b);b.J=d}else c=!!a.o;c?(d=a.o,T(b),b.o=d):c=null!=a.P;d=a.m;if(c)Cb(b,a.P);else if(c=!!a.m){if("/"!=d.charAt(0))if(this.o&&!this.m)d="/"+d;else{var e=b.m.lastIndexOf("/");-1!=e&&(d=b.m.substr(0,e+1)+d)}e=d;if(".."==e||"."==e)d="";else if(-1!=e.indexOf("./")||-1!=e.indexOf("/.")){for(var d=0==e.lastIndexOf("/",0),e=e.split("/"),f=[],g=0;g<e.length;){var h=e[g++];"."==h?d&&g==e.length&&f.push(""):".."==
h?((1<f.length||1==f.length&&""!=f[0])&&f.pop(),d&&g==e.length&&f.push("")):(f.push(h),d=!0)}d=f.join("/")}else d=e}c?(T(b),b.m=d):c=""!==a.i.toString();c?Db(b,a.i.clone()):c=!!a.H;c&&(a=a.H,T(b),b.H=a);return b};S.prototype.clone=function(){return new S(this)};
var Bb=function(a,b,c){T(a);a.v=c?U(b,!0):b;a.v&&(a.v=a.v.replace(/:$/,""))},Cb=function(a,b){T(a);if(b){b=Number(b);if(isNaN(b)||0>b)throw Error("Bad port number "+b);a.P=b}else a.P=null},Db=function(a,b,c){T(a);b instanceof V?(a.i=b,a.i.sa(a.h)):(c||(b=W(b,Ib)),a.i=new V(b,0,a.h))},T=function(a){if(a.Ka)throw Error("Tried to modify a read-only Uri");};S.prototype.sa=function(a){this.h=a;this.i&&this.i.sa(a);return this};
var U=function(a,b){return a?b?decodeURI(a.replace(/%25/g,"%2525")):decodeURIComponent(a):""},W=function(a,b,c){return r(a)?(a=encodeURI(a).replace(b,Jb),c&&(a=a.replace(/%25([0-9a-fA-F]{2})/g,"%$1")),a):null},Jb=function(a){a=a.charCodeAt(0);return"%"+(a>>4&15).toString(16)+(a&15).toString(16)},Eb=/[#\/\?@]/g,Gb=/[\#\?:]/g,Fb=/[\#\?]/g,Ib=/[\#\?@]/g,Hb=/#/g,V=function(a,b,c){this.b=this.a=null;this.g=a||null;this.h=!!c},X=function(a){a.a||(a.a=new Q,a.b=0,a.g&&Ab(a.g,function(b,c){a.add(decodeURIComponent(b.replace(/\+/g,
" ")),c)}))};k=V.prototype;k.add=function(a,b){X(this);this.g=null;a=Y(this,a);var c=this.a.get(a);c||this.a.set(a,c=[]);c.push(b);this.b+=1;return this};k.remove=function(a){X(this);a=Y(this,a);return this.a.D(a)?(this.g=null,this.b-=this.a.get(a).length,this.a.remove(a)):!1};k.D=function(a){X(this);a=Y(this,a);return this.a.D(a)};k.forEach=function(a,b){X(this);this.a.forEach(function(c,d){ha(c,function(c){a.call(b,c,d,this)},this)},this)};
k.M=function(){X(this);for(var a=this.a.I(),b=this.a.M(),c=[],d=0;d<b.length;d++)for(var e=a[d],f=0;f<e.length;f++)c.push(b[d]);return c};k.I=function(a){X(this);var b=[];if(r(a))this.D(a)&&(b=ja(b,this.a.get(Y(this,a))));else{a=this.a.I();for(var c=0;c<a.length;c++)b=ja(b,a[c])}return b};k.set=function(a,b){X(this);this.g=null;a=Y(this,a);this.D(a)&&(this.b-=this.a.get(a).length);this.a.set(a,[b]);this.b+=1;return this};k.get=function(a,b){var c=a?this.I(a):[];return 0<c.length?String(c[0]):b};
k.toString=function(){if(this.g)return this.g;if(!this.a)return"";for(var a=[],b=this.a.M(),c=0;c<b.length;c++)for(var d=b[c],e=encodeURIComponent(String(d)),d=this.I(d),f=0;f<d.length;f++){var g=e;""!==d[f]&&(g+="="+encodeURIComponent(String(d[f])));a.push(g)}return this.g=a.join("&")};k.clone=function(){var a=new V;a.g=this.g;this.a&&(a.a=this.a.clone(),a.b=this.b);return a};var Y=function(a,b){var c=String(b);a.h&&(c=c.toLowerCase());return c};
V.prototype.sa=function(a){a&&!this.h&&(X(this),this.g=null,this.a.forEach(function(a,c){var b=c.toLowerCase();c!=b&&(this.remove(c),this.remove(b),0<a.length&&(this.g=null,this.a.set(Y(this,b),ka(a)),this.b+=a.length))},this));this.h=a};var Kb=function(a){this.ma=a||{cookie:""}};k=Kb.prototype;k.set=function(a,b,c,d,e,f){if(/[;=\s]/.test(a))throw Error('Invalid cookie name "'+a+'"');if(/[;\r\n]/.test(b))throw Error('Invalid cookie value "'+b+'"');void 0!==c||(c=-1);e=e?";domain="+e:"";d=d?";path="+d:"";f=f?";secure":"";c=0>c?"":0==c?";expires="+(new Date(1970,1,1)).toUTCString():";expires="+(new Date(ea()+1E3*c)).toUTCString();this.ma.cookie=a+"="+b+e+d+c+f};
k.get=function(a,b){for(var c=a+"=",d=(this.ma.cookie||"").split(";"),e=0,f;e<d.length;e++){f=x(d[e]);if(0==f.lastIndexOf(c,0))return f.substr(c.length);if(f==a)return""}return b};k.remove=function(a,b,c){var d=this.D(a);this.set(a,"",0,b,c);return d};k.M=function(){return Lb(this).keys};k.I=function(){return Lb(this).values};k.D=function(a){return void 0!==this.get(a)};
var Lb=function(a){a=(a.ma.cookie||"").split(";");for(var b=[],c=[],d,e,f=0;f<a.length;f++)e=x(a[f]),d=e.indexOf("="),-1==d?(b.push(""),c.push(e)):(b.push(e.substring(0,d)),c.push(e.substring(d+1)));return{keys:b,values:c}},Mb=new Kb("undefined"==typeof document?null:document);Mb.mb=3950;var Nb=function(){var a=(Mb.get("GuidedHelpResume")||"").split(":"),b=a[2];a:{for(c in Fa)if(Fa[c]==b){var c=!0;break a}c=!1}return{G:parseInt(a[0],10)||0,w:a[1]||"",source:(c?b:void 0)||"CUSTOM"}};var Ob={},Qb=function(a,b){return Pb({R:b.R,document:b.document,F:b.F||"https://clients6.google.com",B:b.B,N:b.N,locale:b.locale}).then(function(){var c=b.w,d=b.Ra,e=b.Ea,f=b.source||"CUSTOM",g=b.document;return p("help.guide.loadFlow")(a,c,d,e,f,g)})},Sb=function(a,b,c,d,e,f,g,h,n,B){a=B||window.top.location;if(!Rb(a).G)return!1;n=n||"";h=h||void 0;d=d||void 0;a=Rb(a||window.top.location);b=a.G?Qb(a.G,{B:n,document:g,F:h,N:b,locale:c,source:a.source,w:a.w,R:d}):bb();I(b);return!0},Rb=function(a){a=
a instanceof S?a.clone():new S(a,void 0);var b=a.i.get("ghstartsource")||"";return{G:parseInt(a.i.get("ghstartflowid"),10)||0,w:a.i.get("ghstartstepid")||"",source:{helpcenter:"HELPCENTER",email:"EMAIL",chat:"CHAT",forum:"FORUM",marketing:"MARKETING",onebox:"ONEBOX",testing:"TESTING"}[b]||"LINK"}},Pb=function(a){window.guidedhelp=window.guidedhelp||{};if(window.guidedhelp.loaded)var b=ab();else Tb||(Tb=sb().then()),b=Tb;return b.then(function(){var b=a.N,d=a.locale,e=a.R,f=a.document,g=a.F,h=a.B;
p("help.guide.init")(b,d,e,f,g,h,Ob)})},Tb=null,Ub=function(a,b,c,d,e,f,g,h,n){if(!Nb().G)return!1;a=n||"";g=g||void 0;h=h||void 0;d=d||void 0;e=Nb();e.G?(Mb.remove("GuidedHelpResume","/",""),b=Qb(e.G,{B:a,document:g,F:h,N:b,locale:c,Ra:!1,w:e.w||void 0,R:d,source:e.source})):b=bb();I(b);return!0};m("hgb.loadFlow",function(a,b,c,d,e,f,g,h,n,B,bc,cc){I(Qb(a,{B:cc||"",Ea:n||!1,document:B||void 0,F:bc||void 0,N:c,locale:d,R:e||void 0,source:"CUSTOM",w:h||void 0}))},void 0);
m("hgb.resumeCookiedFlow",Ub,void 0);m("hgb.startFlowFromUrl",Sb,void 0);var Vb=/^[\w+/]+[=]{0,2}$/;var Wb=function(a,b,c){a.timeOfStartCall=(new Date).getTime();var d=c||l,e=d.document,f;a:{if((f=(d||l).document.querySelector("script[nonce]"))&&(f=f.nonce||f.getAttribute("nonce"))&&Vb.test(f))break a;f=void 0}f&&(a.nonce=f);if("help"==a.flow){var g=p("document.location.href",d);!a.helpCenterContext&&g&&(a.helpCenterContext=g.substring(0,1200));g=!0;if(b&&JSON&&JSON.stringify){var h=JSON.stringify(b);(g=1200>=h.length)&&(a.psdJson=h)}g||(b={invalidPsd:!0})}b=[a,b,c];d.GOOGLE_FEEDBACK_START_ARGUMENTS=
b;c=a.serverUri||"//www.google.com/tools/feedback";if(g=d.GOOGLE_FEEDBACK_START)g.apply(d,b);else{var d=c+"/load.js?",n;for(n in a)b=a[n],null!=b&&!ba(b)&&(d+=encodeURIComponent(n)+"="+encodeURIComponent(b)+"&");a=e.createElement("script");f&&a.setAttribute("nonce",f);a.src=d;e.body.appendChild(a)}};m("userfeedback.api.startFeedback",Wb,void 0);var Xb=function(a,b){var c=a.serverUri||"//www.gstatic.com/feedback";l.GOOGLE_HELP_SESSION_ARGUMENTS=arguments;var d=window.document,e=d.createElement("script");e.src=c+"/session_load.js";d.body.appendChild(e)};m("userfeedback.api.help.resumeOpenHelpSession",Xb,void 0);m("userfeedback.api.help.startHelpWithChatSupport",function(a,b){a.flow="help";Wb(a,b)},void 0);var Yb=function(a,b){Xb(a,b);var c=a.serverUri||"//www.google.com/tools/feedback";l.GOOGLE_HELP_CHAT_ARGUMENTS=arguments;var d=window.document,e=d.createElement("script");e.src=c+"/chat_load.js";d.body.appendChild(e)};m("userfeedback.api.help.loadChatSupport",Yb,void 0);var Z=function(a,b){this.Na=a;this.Oa=b.receiverUri;this.V=b.locale||b.locale||"en".replace(/-/g,"_");this.A=b.window||b.window||top;this.ra=b.wb||b.productData||{};this.na=b.F||b.environment||"https://clients6.google.com";this.$=b.rb||b.helpCenterPath||"";this.ia=b.B||b.apiKey||"";this.Qa=b.xb||b.renderApiUri||""};m("help.service.Lazy",Z,void 0);Z.create=function(a,b){var c=new Z(a,b);Ub(0,c.$,c.V,null,0,0,c.A.document,c.na,c.ia)||Sb(0,c.$,c.V,null,0,0,c.A.document,c.na,c.ia,c.A.location);return c};
Z.prototype.Ta=function(a){Zb();Wb($b(this,a),this.ra,this.A)};Z.prototype.startFeedback=Z.prototype.Ta;Z.prototype.Ua=function(a,b){var c=b||{};I(Qb(a,{B:this.ia,document:this.A.document,F:this.na,N:this.$,locale:this.V,w:c.stepId,source:c.source,R:c.theme}));window.T||(window.T={});window.T.sb=c.onerror;window.T.tb=c.ondismiss;window.T.vb=c.onstepenter;window.T.ub=c.onload};Z.prototype.startGuide=Z.prototype.Ua;Z.prototype.Wa=function(){var a=p("help.guide.dismissFlow");a&&a()};
Z.prototype.stopGuide=Z.prototype.Wa;
Z.prototype.Va=function(a){var b=a||{};Zb();Wb(ac(this,a),this.ra,this.A);if(b.enableCache){var c;a=null;try{(c=this.A.localStorage||null)&&(a=c["helpPanelHtml_"+this.V])}catch(g){}if(c=a)if(a=this.A.document,b=b.customZIndex,!a.getElementById("google-feedback-wizard")){var d={id:"google-feedback-wizard",style:"border: 0; vertical-align:bottom; background: none; display: block; width: 100%; height: 100%; z-index: 10000000; top: -100%; left: 0; visibility: visible; opacity: 1;position: fixed",frameborder:"0",
allowTransparency:"true"},e=a.createElement("iframe");for(f in d)e.setAttribute(f,d[f]);b&&(e.style.zIndex=b);a.body.appendChild(e);var f=e.contentDocument||e.contentWindow.document;f.open();f.write(c);f.close()}}};Z.prototype.startHelp=Z.prototype.Va;
var $b=function(a,b){var c=b||{};return{bucket:c.bucket,locale:a.V,callback:c.onend||q,serverUri:a.Oa,productId:a.Na,productVersion:c.productVersion,authuser:c.authuser,abuseLink:c.abuseLink,customZIndex:c.customZIndex,flow:"wizard",enableAnonymousFeedback:c.enableAnonymousFeedback,allowNonLoggedInFeedback:c.allowNonLoggedInFeedback}},ac=function(a,b){var c=b||{},d=$b(a,b);pa(d,{anchor:c.anchor,contactBucket:c.contactBucket,flow:"help",helpCenterContext:c.context,helpCenterPath:a.$,enableSendFeedback:c.enableSendFeedback||
!1,enableCache:c.enableCache,defaultHelpArticleId:c.defaultHelpArticleId,newApi:!0,suggestHost:c.suggestHost,renderApiUri:a.Qa});return d};Z.prototype.Ma=function(a){var b=a||{};a=ac(this,a);pa(a,{escalationJSONString:b.escalationJSONString});Yb(a,this.ra)};Z.prototype.loadChatSupport=Z.prototype.Ma;Z.prototype.Pa=function(a,b,c){dc().register(a,b,c)};Z.prototype.registerHelpAction=Z.prototype.Pa;Z.prototype.Ha=function(a,b){var c=dc().ha[a];c&&c.ba()&&c.la.apply(null,b||[])};
Z.prototype.executeHelpAction=Z.prototype.Ha;Z.prototype.Ja=function(a){return dc().ba(a)};Z.prototype.isHelpActionApplicable=Z.prototype.Ja;var Zb=function(){var a=window.GOOGLE_FEEDBACK_DESTROY_FUNCTION;a&&a()},dc=function(){var a=p("help.globals.actions",top);a||(a=new C,m("help.globals.actions",a,top));return a};}).call(this);
