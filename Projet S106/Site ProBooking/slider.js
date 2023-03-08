const slides = document.getElementsByClassName("slider-slide");

function switchSlide(i) {
  for (let j = 0; j < slides.length; j++) {
    slides[j].classList.remove("active");
  }

  slides[i].classList.add("active");
}

function interval() {
  setInterval(() => {
    switchSlide(i);
    i++;
    if (i >= slides.length) i = 0;
  }, 5000);
}

let i = 1;
let theInterval = interval();

