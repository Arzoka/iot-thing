// Bever drop function

function dropImage() {
    var image = document.getElementById("beaver");
    image.style.display = "block"; 

    var yPos = 0; 
    var dropInterval = setInterval(function() {
      yPos += 1.5; 
      image.style.top = yPos + "rem";
      image.style.rotate = "-30deg"
      
     
      if (yPos >= window.innerHeight) {
        clearInterval(dropInterval);
        image.style.display = "none"; 
        image.style.top = "px"; 
        ;
      }
    }, 5); 
  }

const body = document.querySelector('body');
const burn = document.getElementById('burn');
const highlight = document.getElementById('highlight');
const content = document.getElementById('content');

let on = false;

function ToggleAnimation () {
	if (on) {
		highlight.classList.remove('highlight');
		burn.classList.remove('burn');
		content.classList.remove('content');
		on = false;
		return;
	}

	highlight.classList.add('highlight');
	burn.classList.add('burn');
	content.classList.add('content');
	on = true;
};
