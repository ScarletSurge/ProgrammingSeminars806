using Microsoft.AspNetCore.Mvc;

using RGU.WebProgramming.Server.REST.Models;

namespace RGU.WebProgramming.Server.REST.API.Controller;

/// <summary>
/// 
/// </summary>
[ApiController]
[Route("api/controller_example")]
[Produces("application/json")]
public sealed class ControllerExample:
    ControllerBase
{
    
    #region Fields
    
    /// <summary>
    /// 
    /// </summary>
    private readonly ILogger<ControllerExample> _logger;
    
    #endregion
    
    #region Constructors
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="logger"></param>
    /// <exception cref="ArgumentNullException"></exception>
    public ControllerExample(
        ILogger<ControllerExample> logger)
    {
        _logger = logger ?? throw new ArgumentNullException(nameof(logger));
    }
    
    #endregion
    
    #region API methods
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="cancellationToken"></param>
    /// <returns></returns>
    [HttpGet("method_example_get")]
    public async Task<IActionResult> MethodExampleGetAsync(
        CancellationToken cancellationToken = default)
    {
        try
        {
            _logger.LogInformation($"Got GET request");

            //

            return StatusCode(StatusCodes.Status200OK);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "An exception occured");
            return StatusCode(StatusCodes.Status500InternalServerError);
        }
    }
    
    /// <summary>
    /// 
    /// </summary>
    /// <param name="modelExampleInstance"></param>
    /// <param name="cancellationToken"></param>
    /// <returns></returns>
    [HttpPost("method_example_post")]
    public async Task<IActionResult> MethodExamplePostAsync(
        [FromBody] ModelExample modelExampleInstance,
        CancellationToken cancellationToken = default)
    {
        try
        {
            _logger.LogInformation($"Got request body: {modelExampleInstance}");

            //

            return StatusCode(StatusCodes.Status200OK);
        }
        catch (Exception ex)
        {
            _logger.LogError(ex, "An exception occured");
            return StatusCode(StatusCodes.Status500InternalServerError);
        }
    }
    
    #endregion
    
}