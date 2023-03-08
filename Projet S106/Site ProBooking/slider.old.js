let img_slider = document.getElementsByClassName('img_slider');
let text_slider = document.getElementsByClassName('text-box');

let etape_img = 0;
let etape_txt = 0;

let nbr_img = img_slider.length;
let nbr_txt = text_slider.length;

let precedent = document.querySelector('.precedent');
let suivant = document.querySelector('.suivant');

function enleverActiverImages() {
  for (let i = 0; i < nbr_img; i++) {
    img_slider[i].classList.remove('active');
  }
}

function enleverActiverTextes() {
  for (let i = 0; i < nbr_txt; i++) {
    text_slider[i].classList.remove('active');
  }
}

suivant.addEventListener('click', function() {
  etape_img++;
  if (etape_img >= nbr_img) {
    etape_img = 0;
  }
  enleverActiverImages();
  img_slider[etape_img].classList.add('active');

  etape_txt++;
  if (etape_txt >= nbr_txt) {
    etape_txt = 0;
  }
  enleverActiverTextes();
  text_slider[etape_txt].classList.add('active');
})

precedent.addEventListener('click', function() {
  etape_img--;
  if (etape_img < 0) {
    etape_img = nbr_img - 1;
  }
  enleverActiverImages();
  img_slider[etape_img].classList.add('active');

  etape_txt--;
  if (etape_txt < 0) {
    etape_txt = nbr_txt - 1;
  }
  enleverActiverTextes();
  text_slider[etape_txt].classList.add('active');
})

setInterval(function() {
  etape_img++;
  if (etape_img >= nbr_img) {
    etape_img = 0;
  }
  enleverActiverImages();
  img_slider[etape_img].classList.add('active');

  etape_txt++;
  if (etape_txt >= nbr_txt) {
    etape_txt = 0;
  }
  enleverActiverTextes();
  text_slider[etape_txt].classList.add('active');
}, 15000)