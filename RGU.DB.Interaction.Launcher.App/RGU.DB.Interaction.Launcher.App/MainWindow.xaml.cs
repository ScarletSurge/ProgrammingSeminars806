using System.Data;
using Npgsql;
using System.Windows;

namespace RGU.DB.Interaction.Launcher.App;

/// <summary>
/// Interaction logic for MainWindow.xaml
/// </summary>
public partial class MainWindow : Window
{
    public MainWindow()
    {
        InitializeComponent();
    }

    private async void ButtonBase_OnClick(
        object sender,
        RoutedEventArgs e)
    {
        var gotResults = new List<(string?, string?, string?)>();
        
        try
        {
            string? surname, name, patronymic;

            await using var connection =
                new NpgsqlConnection(
                    "Server=127.0.0.1;Port=5432;Database=helloworld;User Id=postgres;Password=postgres;");
            await connection.OpenAsync();

            await using var command = new NpgsqlCommand("SELECT * FROM my_function()", connection)
            {
                CommandType = CommandType.Text
            };

            await using var reader = await command.ExecuteReaderAsync();

            while (await reader.ReadAsync())
            {
                surname = reader.GetValue("surname") is DBNull
                    ? null
                    : reader.GetString("surname");
                
                name = reader.GetValue("name") is DBNull
                    ? null
                    : reader.GetString("name");
                
                patronymic = reader.GetValue("patronymic") is DBNull
                    ? null
                    : reader.GetString("patronymic");
                
                gotResults.Add((surname, name, patronymic));
            }
        }
        catch (NpgsqlException ex)
        {
            MessageBox.Show(ex.Message);
        }

        var x = 10;
    }
    
}