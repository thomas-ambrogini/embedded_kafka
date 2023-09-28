$(document).ready(function () {
    // Attach a click event handler to links with class "load-page"
    $(".load-page").click(function (e) {
        e.preventDefault(); // Prevent the default link behavior

        // Get the URL from the data-url attribute
        var url = $(this).data("url");

        console.log(url)

        // Use AJAX to fetch the content from the URL
        $.ajax({
            url: url,
            method: "GET",
            success: function (data) {
                // Replace the content of the "content" div with the fetched data
                $(".content").html(data);
            },
            error: function () {
                // Handle any errors here
                alert("Failed to load page");
            }
        });
    });
});
