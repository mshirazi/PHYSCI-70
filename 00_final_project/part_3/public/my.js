var precision = 16;
var editRow = null;
window.onload=function(){
  window.ref = firebase.database().ref();
}

function reduce(numerator,denominator){
	var gcd = function gcd(a,b){
		return b ? gcd(b, a%b) : a;
	};
	gcd = gcd(numerator,denominator);
	return [numerator/gcd, denominator/gcd];
}
$(function() {
	var ref = firebase.database().ref();

	$('input').filter( function(){return this.id == 'speed' } ).each(function(){  
		var $slider = $(this),
		$text_box = $('#'+$(this).attr('link-to'));
		
		$text_box.val(this.value);
		
		$slider.change(function(){
			$text_box.val(this.value);
			ref.update({
				"speed": $text_box.val()
			});
		});
		
		$text_box.change(function(){
			$slider.val($text_box.val());
			ref.update({
				"speed": $text_box.val()
			});
		});

	});
});

$(function() {
	$('input').filter( function(){return this.id == 'thickness' } ).each(function(){  
			var ref = firebase.database().ref();

		var $slider = $(this),
		$text_box = $('#'+$(this).attr('link-to'));
		
		$text_box.val(this.value);
		document.getElementById("min").innerHTML = 1;
		document.getElementById("max").innerHTML = 2;
		$slider.change(function(){
			$text_box.val(this.value);
			var val = reduce($text_box.val(), precision);
			document.getElementById("min").innerHTML = val[0];
			document.getElementById("max").innerHTML = val[1];
			ref.update({
				"thickness": $text_box.val()
			});
		});
		
		$text_box.change(function(){
			$slider.val($text_box.val());
			var val = reduce($text_box.val(), precision);
			document.getElementById("min").innerHTML = val[0];
			document.getElementById("max").innerHTML = val[1];
			ref.update({
				"thickness": $text_box.val()
			});
		});

	});
});


// Reduce a fraction by finding the Greatest Common Divisor and dividing by it.

$(function() {
	var bindButtons = function(){

		$('#on_off').on('click', 'button', function( e ){

			e.preventDefault();

			$(this)
			.addClass('selected')
			.removeClass('disabled')
			.siblings()
			.removeClass('selected')
			.addClass('disabled');
		});

	};

// Init binding
bindButtons();

// Get your answer
var answer = $('#buttons .selected').data('answer');
});

$(function() {
	var bindButtons = function(){

		$('#up_down').on('click', 'button', function( e ){

			e.preventDefault();

			$(this)
			.addClass('selected')
			.removeClass('disabled')
			.siblings()
			.removeClass('selected')
			.addClass('disabled');
		});

	};

// Init binding
bindButtons();

// Get your answer
var answer = $('#buttons .selected').data('answer');
});

$(function() {
	

});

function turnOn(){
		var ref = firebase.database().ref();
		console.log("turning on");
		ref.update({
			"status": "on"
		});
	}

	function turnOff(){
		var ref = firebase.database().ref();
		console.log("turning off");
		ref.update({
			"status": "off"
		});
	}	

	function turnUp(){
		var ref = firebase.database().ref();
		console.log("turning up");
		ref.update({
			"direction": "up"
		});
	}

	function turnDown(){
		var ref = firebase.database().ref();
		console.log("turning down");
		ref.update({
			"direction": "down"
		});
	}	

// Current product being edited
var editRow = null;

function productDisplay(ctl) {
	editRow = $(ctl).parents("tr");
	var cols = editRow.children("td");

	$("#productname").val($(cols[1]).text());
	$("#introdate").val($(cols[2]).text());
	$("#url").val($(cols[3]).text());

      // Change Update Button Text
      $("#updateButton").text("Update");
  }

function productUpdate() {
  	if ($("#updateButton").text() == "Update") {
  		productUpdateInTable();
  	}
  	else {
  		productAddToTable();
  	}

      // Clear form fields
      formClear();

      // Focus to product name field
      $("#productname").focus();
  }

    // Add product to <table>
    function productAddToTable() {
      // First check if a <tbody> tag exists, add one if not
      if ($("#productTable tbody").length == 0) {
      	$("#productTable").append("<tbody></tbody>");
      }

      // Append product to table
      $("#productTable tbody").append(
      	productBuildTableRow());
  }

    // Update product in <table>
    function productUpdateInTable() {
      // Add changed product to table
      $(editRow).after(productBuildTableRow());

      // Remove original product
      $(editRow).remove();

      // Clear form fields
      formClear();

      // Change Update Button Text
      $("#updateButton").text("Add");
  }

    // Build a <table> row of Product data
    function productBuildTableRow() {
    	var ret =
    	"<tr>" +
    	"<td>" +
    	"<button type='button' " +
    	"onclick='productDisplay(this);' " +
    	"class='btn btn-default'>" +
    	"<span class='glyphicon glyphicon-edit' />" +
    	"</button>" +
    	"</td>" +
    	"<td>" + $("#productname").val() + "</td>" +
    	"<td>" + $("#introdate").val() + "</td>" +
    	"<td>" + $("#url").val() + "</td>" +
    	"<td>" +
    	"<button type='button' " +
    	"onclick='productDelete(this);' " +
    	"class='btn btn-default'>" +
    	"<span class='glyphicon glyphicon-remove' />" +
    	"</button>" +
    	"</td>" +
    	"</tr>"

    	return ret;
    }

    // Delete product from <table>
    function productDelete(ctl) {
    	$(ctl).parents("tr").remove();
    }

    // Clear form fields
    function formClear() {
    	$("#productname").val("");
    	$("#introdate").val("");
    	$("#url").val("");
    }

    function productDisplay(ctl) {
    	editRow = $(ctl).parents("tr");
    	var cols = editRow.children("td");

    	$("#presetname").val($(cols[1]).text());
    	$("#preset_thickness").val($(cols[2]).text());
    	$("#preset_length").val($(cols[3]).text());

	      // Change Update Button Text
	      $("#updateButton").text("Update");
	  }

	  function productUpdate() {
	  	if ($("#updateButton").text() == "Update") {
	  		productUpdateInTable();
	  	}
	  	else {
	  		productAddToTable();
	  	}

	      // Clear form fields
	      formClear();

	      // Focus to product name field
	      $("#presetname").focus();
	  }

	    // Add product to <table>
	    function productAddToTable() {
	      // First check if a <tbody> tag exists, add one if not
	      if ($("#productTable tbody").length == 0) {
	      	$("#productTable").append("<tbody></tbody>");
	      }

	      // Append product to table
	      $("#productTable tbody").append(
	      	productBuildTableRow());
	  }

	    // Update product in <table>
	    function productUpdateInTable() {
	      // Add changed product to table
	      $(editRow).after(productBuildTableRow());

	      // Remove original product
	      $(editRow).remove();

	      // Clear form fields
	      formClear();

	      // Change Update Button Text
	      $("#updateButton").text("Add");
	  }



	    // Build a <table> row of Product data
	    function productBuildTableRow() {
	    	var ret =
	    	"<tr>" +
	    	"<td>" +
	    	"<button type='button' " +
	    	"onclick='productDisplay(this);' " +
	    	"class='btn btn-default'>" +
	    	"<span class='glyphicon glyphicon-edit' />" +
	    	"</button>" +
	    	"</td>" +
	    	"<td>" + $("#presetname").val() + "</td>" +
	    	"<td>" + $("#preset_thickness").val() + "</td>" +
	    	"<td>" + $("#preset_length").val() + "</td>" +
	    	"<td>" +
	    	"<button type='button' " +
	    	"onclick='productDelete(this);' " +
	    	"class='btn btn-default'>" +
	    	"<span class='glyphicon glyphicon-remove' />" +
	    	"</button>" +
	    	"</td>" +
	    	"</tr>"

	    	return ret;
	    }

	    // Delete product from <table>
	    function productDelete(ctl) {
	    	$(ctl).parents("tr").remove();
	    }

	    // Clear form fields
	    function formClear() {
	    	$("#presetname").val("");
	    	$("#preset_thickness").val("");
	    	$("#preset_length").val("");
	    }

$(function() {

		//const db = firebase.database().ref();
		// Initialize Firebase

		// Get a database reference to our blog
		var ref = firebase.database().ref();
		//var vall = firebase.database().ref('LED_STATUS');
		ref.update({"LED_STATUS" : "OFF"});
		ref.update({"status" : "off"});
		// make the buttons call the function below 

		ref.on('value', function(snapshot) {
			var vall = snapshot.val();
			console.log(vall);
	  //document.getElementById("demo").innerHTML = vall.LED_STATUS;
	});
	});